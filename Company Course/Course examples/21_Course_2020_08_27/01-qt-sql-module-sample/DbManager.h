#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>

class DbManager
{
public:
    DbManager(const QString& path);
    ~DbManager();

    void addBook(const QString& name, const QString& author,
                 const int price, const int publishDate);

    void printAllBooks();
    void updateBooksPrice(const int id, const int price);
    void deleteBook(const int id);
    void deleteAllBooks();
private:
    QSqlDatabase _db;
};

#endif // DBMANAGER_H
