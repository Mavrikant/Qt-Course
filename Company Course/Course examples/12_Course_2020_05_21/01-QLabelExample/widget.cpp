//widget.cpp
#include "widget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMovie>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    labelImg = new QLabel();//parent belirtmeye gerek yok. Layoutun icinde oldugu widget parent olacak
    labelText = new QLabel();
    labelMovie = new QLabel();

    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();
    QPixmap img;
    img.load(":/images/Al-Khwarizmi.jpg");
    labelImg->setPixmap(img);
    movie = new QMovie(this);//new QMovie("images/al-Khwarizmi.gif");
    movie->setFileName("images/al-Khwarizmi.gif");
    labelMovie->setMovie(movie);
    movie->setScaledSize(QSize(1536 / 2, 864 / 2));
    QString str = "Al-Khwārizmī, in full Muḥammad ibn Mūsā al-Khwārizmī, \n\
(born c. 780 —died c. 850), Muslim mathematician and astronomer\n \
whose major works introduced Hindu-Arabic numerals and the concepts\n \
of algebra into European mathematics. Latinized versions of his name\n \
and of his most famous book title live on in the terms algorithm and algebra.\n\
Al-Khwārizmī lived in Baghdad, where he worked at the “House of Wisdom” \n\
(Dār al-Ḥikma) under the caliphate of al-Maʾmūn. The House of Wisdom \n\
acquired and translated scientific and philosophic treatises, particularly Greek\n\
, as well as publishing original research. Al-Khwārizmī’s work on elementary\n\
 algebra, Al-Kitāb al-mukhtaṣar fī ḥisāb al-jabr waʾl-muqābala \n\
(“The Compendious Book on Calculation by Completion and Balancing”), \n\
was translated into Latin in the 12th century, from which the title \n\
and term algebra derives. Algebra is a compilation of rules, together\n\
 with demonstrations, for finding solutions of linear and quadratic equations\n\
 based on intuitive geometric arguments, rather than the abstract notation\n\
 now associated with the subject. Its systematic, demonstrative approach\n\
 distinguishes it from earlier treatments of the subject. It also contains\n\
 sections on calculating areas and volumes of geometric figures and on the\n\
 use of algebra to solve inheritance problems according to proportions prescribed\n\
 by Islamic law. Elements within the work can be traced from Babylonian mathematics\n\
 of the early 2nd millennium bce through Hellenistic, Hebrew, and Hindu treatises.";

    labelText->setText(str);
    labelText->setFont(QFont("Purisa", 10));

    hbox->addWidget(labelText);
    hbox->addWidget(labelImg);
    vbox->addWidget(labelMovie);

    vbox->addLayout(hbox);

    setLayout(vbox);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::playMovie);
    timer->setSingleShot(true);
    timer->start(500);

}

Widget::~Widget()
{

}

void Widget::playMovie()
{
    movie->start();
}
