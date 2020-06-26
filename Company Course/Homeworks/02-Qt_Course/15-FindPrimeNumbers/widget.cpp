#include "widget.h"
#include <QtWidgets>
#include <QtConcurrent/QtConcurrent>

Widget::Widget(QWidget *parent): QWidget(parent)
{
    stopped = true;
    elapsedTimer = new QElapsedTimer;
    QGridLayout *mainLayout = new QGridLayout();

    numberOfThreads = new QSpinBox(this);
    numberOfThreads->setValue(QThread::idealThreadCount());
    numberOfThreads->setMinimum(0);
    numberOfThreads->setMaximum(QThread::idealThreadCount() * 200);
    mainLayout->addWidget(new QLabel(tr("Nr Of Threads:"), this), 0, 0);
    mainLayout->addWidget(numberOfThreads, 0, 1);

    btnQuit = new QPushButton(tr("&Quit"), this);
    btnStartCancel = new QPushButton(tr("&Start"), this);

    maxInterval = new QSpinBox(this);
    maxInterval->setValue(8);
    maxInterval->setMinimum(1);
    maxInterval->setMaximum(10);

    mainLayout->addWidget(new QLabel(QString(tr("Upper Limit (%1^x):")).arg(NumberBase), this), 0, 2);
    mainLayout->addWidget(maxInterval, 0, 3);
    mainLayout->addWidget(btnStartCancel, 1, 0);
    mainLayout->addWidget(btnQuit, 1, 1);

    logEdit = new QPlainTextEdit(this);
    mainLayout->addWidget(logEdit, 2, 0, 1, 6);

    setLayout(mainLayout);

    connect(btnStartCancel, &QPushButton::clicked, this, &Widget::calculateOrCancel);
    connect(btnQuit, &QPushButton::clicked, qApp, &QApplication::quit);
}

void Widget::updateUi()
{
    if (stopped)
        btnStartCancel->setText(tr("&Start"));
    else
        btnStartCancel->setText(tr("&Cancel"));
}

void Widget::calculateOrCancel()
{
    stopped = true;
    if (QThreadPool::globalInstance()->activeThreadCount())
        QThreadPool::globalInstance()->waitForDone();
    if (btnStartCancel->text() == tr("&Cancel"))
    {
        updateUi();
        return;
    }

    qint32 max;
    max = pow(NumberBase, maxInterval->value());
    logEdit->clear();
    findPrimesParallel(1, max);
}

void Widget::checkIfDone()
{
    if (QThreadPool::globalInstance()->activeThreadCount())
        QTimer::singleShot(PollTimeout, this, SLOT(checkIfDone()));
    else
    {
        QString message;

        if (done == total)
        {
            message = tr("All primes tested");
            int nrOfThreads = numberOfThreads->value() ? numberOfThreads->value() : QThread::idealThreadCount();
            int nMilliseconds = elapsedTimer->elapsed();
            message += QString(tr("\nNumber of threads: %1 Elapsed Time: %2ms")).arg(nrOfThreads).arg(
                           nMilliseconds);
        }
        else
        {
            message = tr("Calculated %n/%1 blocks(s)", "", done).arg(total);
        }

        logEdit->appendPlainText("\n" + message);
        stopped = true;
        updateUi();
    }
}


void Widget::findPrimesParallel(quint32 startNum, quint32 endNum)
{
    stopped = false;
    updateUi();
    done = 0;
    int nrOfThreads = numberOfThreads->value() ? numberOfThreads->value() * 10 :
                      QThread::idealThreadCount() * 10;

    total = nrOfThreads;
    quint32 dnumbersPerThread = (endNum - startNum) / nrOfThreads;
    quint32 numbersPerThread = dnumbersPerThread;
    quint32 offset = 0;
    elapsedTimer->start();

    /* Burayı eşit işlem aralıklarına bölmek için 1'den endNum'e kadar olan sayıların kareköklerinin toplamını hesaplayıp bunu eşit aralıklara bölmemiz lazım.
     * Bunu yapan Hurwitz-zeta fonksiyonu var fakat bunun implementasyonu gerçenten bütün sayıların karakökünü hesaplayıp topluyor.
     * Nümerik analizle düşük doğruluğa sahip ama daha hızlı bir yöntem bulamadım.
     *
     * QtConcurrent optimal bir şekilde çalıştığı için task sayısını artırmak CPU'nun boş kalmasını engelliyor.
     */


    for (qint32 i = 0; i < nrOfThreads; i++)
    {
        QtConcurrent::run(findPrimes, this, offset, offset + numbersPerThread);
        offset += numbersPerThread;
    }

    checkIfDone();
}

bool Widget::event(QEvent *event)
{
    if (!stopped && event->type() == static_cast<QEvent::Type>(ProgressEvent::EventId))
    {
        ProgressEvent *progressEvent = static_cast<ProgressEvent *>(event);
        Q_ASSERT(progressEvent);
        logEdit->appendPlainText(progressEvent->message);
        if (progressEvent->calculated)
        {
            ++done;
        }
        return true;
    }
    return QWidget::event(event);
}

void Widget::closeEvent(QCloseEvent *event)
{
    stopped = true;
    if (QThreadPool::globalInstance()->activeThreadCount())
    {
        QThreadPool::globalInstance()->waitForDone();
    }
    event->accept();
}

void findPrimes(QObject *receiver,  quint32 startNum, quint32 endNum)
{
    volatile quint32 count = 0;
    for (quint32 i = startNum; i < endNum; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    QApplication::postEvent(receiver, new ProgressEvent(true, startNum, endNum, count,
                                                        QString("[%1-%2) interval contains %3 prime numbers").arg(startNum).arg(endNum).arg(count)));
}

bool isPrime(quint32 number)
{
    quint32 i = 0;
    quint32 known_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
                              67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
                              149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199
                             };
    quint32 known_primes_size = sizeof(known_primes) / sizeof(known_primes[0]);

    const quint32 sqrtNumber = ceil(sqrt(number));

    if (number < 200)
    {
        for (i = 0; i < known_primes_size; i++)
        {
            if (number == known_primes[i])
            {
                return true;
            }
        }
    }

    for (i = 0; i < known_primes_size; i++)
    {
        if (number % known_primes[i] == 0)
        {
            return false;
        }
    }

    for (i = 199;  i < sqrtNumber ; i = i + 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
