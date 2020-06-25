#include "anothermenu.h"
#include <QMenu>
#include <QMenuBar>

AnotherMenu::AnotherMenu(QWidget *parent): QMainWindow(parent)
{
    QPixmap newpix(":/icons/new.png");//Resource dosyasindan new.png iconunu temsil eden QPixmap nesnesi
    QPixmap openpix(":/icons/file.png");
    QPixmap quitpix(":/icons/quit.png");

    QAction *newa = new QAction(newpix, "&New", this);// "New" adinda yeni bir aksiyon olusturuluyor
    QAction *open = new QAction(openpix, "&Open", this);
    QAction *quit = new QAction(quitpix, "Qui&t", this);
    quit->setShortcut(tr("CTRL+Q"));// Olusturulan aksiyona klavye kisayolu ataniyor

    QMenu *file;
    file = menuBar()->addMenu("&File");//QMainWindow'un QMenuBar nesnesine File popup menusu ilave ediliyor
    file->addAction(newa);//Daha once olusturulmus olan "New" adindaki aksiyon popup'a ekleniyor
    file->addAction(open);
    file->addSeparator();//Aksiyonlar arasina ayirici konuluyor
    file->addAction(quit);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);//Menu ikonlarinin gosterimi aktif ediliyor

    //quit aksiyonunun tetiklenmesi uygulamanin kapatilmasi birbirine baglaniyor
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}
