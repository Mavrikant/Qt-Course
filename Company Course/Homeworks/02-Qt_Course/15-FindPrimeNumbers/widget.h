#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
class QComboBox;
class QPushButton;
class QLineEdit;
class QPlainTextEdit;
class QStringList;
class QString;
class QSpinBox;
class QTime;
class QElapsedTimer;


struct ProgressEvent : public QEvent
{
    enum {EventId = QEvent::User};
    explicit ProgressEvent(bool calc_, unsigned long long min_, unsigned long long max_,
                           unsigned int count_, const QString &message_):
        QEvent(static_cast<Type>(EventId)), calculated(calc_), min(min_), max(max_), count(count_),
        message(message_)  {}
    const bool calculated;
    const quint32 min;
    const quint32 max;
    const quint32 count;

    const QString message;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void updateUi();

private slots:
    void checkIfDone();
    void calculateOrCancel();

private:
    const int PollTimeout = 1;
    const int NumberBase = 10;
    int total;
    int done;
    volatile bool stopped;
    QPushButton *btnStartCancel;
    QPushButton *btnQuit;
    QSpinBox *maxInterval;
    QSpinBox *numberOfThreads;
    QPlainTextEdit *logEdit;
    QElapsedTimer *elapsedTimer;

    bool event(QEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void findPrimesParallel(quint32 startNum, quint32 endNum);
};
void findPrimes(QObject *receiver,  quint32 startNum, quint32 endNum);
bool isPrime(quint32 number);
#endif // WIDGET_H
