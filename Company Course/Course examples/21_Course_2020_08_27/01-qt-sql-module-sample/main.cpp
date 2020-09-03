#include <QCoreApplication>

#include "DbManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DbManager dbManager("D:\\Work\\Qt\\qt-sql-module-sample\\estore.db");

    //dbManager.addBook("The C Programming Language", "D. Ritchie", 100, 1978);
    //dbManager.addBook("The C++ Programming Language", "Bjarne Stroustrup", 100, 1985);
    //dbManager.addBook("C++ Primer", "Stanley B. Lippman", 100, 1989);

    dbManager.printAllBooks();

    //dbManager.updateBooksPrice(3, 155);

    //dbManager.deleteBook(2);

    dbManager.deleteAllBooks();
    dbManager.printAllBooks();

    return a.exec();
}
