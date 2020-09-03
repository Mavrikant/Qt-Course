#include "DbManager.h"

DbManager::DbManager(const QString &path)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(path);

    if(!_db.open()) {
        qDebug() << _db.lastError().text();
    }
    else {
        qDebug() << "Database connection ok";
    }
}

DbManager::~DbManager()
{
    if(_db.isOpen())
        _db.close();
}

void DbManager::addBook(const QString &name, const QString &author, const int price, const int publishDate)
{
    QSqlQuery query;

    query.prepare("insert into Books (Name, Author, Price, PublishDate) values "
                  " (:name, :author, :price, :publishDate)");

    query.bindValue(":name", name);
    query.bindValue(":author", author);
    query.bindValue(":price", price);
    query.bindValue(":publishDate", publishDate);

    if(!query.exec()) {
        qDebug() << query.lastError().text();
        return;
    }

    if(query.numRowsAffected() != -1) {
        qDebug() << query.numRowsAffected() << " rows inserted";
    }
}

void DbManager::printAllBooks()
{
    QSqlQuery query;

    if(!query.exec("select * from Books")) {
        qDebug() << query.lastError().text();
        return;
    }

    if(query.driver()->hasFeature(QSqlDriver::QuerySize)) {
        if(query.size() < 1) {
            qDebug() << "No rows";

            return;
        }
    }

    while(query.next()) {
        int id = query.value("Id").toInt();
        QString name = query.value("Name").toString();
        QString author = query.value("Author").toString();
        int price = query.value("Price").toInt();
        int publishDate = query.value("PublishDate").toInt();

        qDebug() << id << "\t" << name << "\t" << author << "\t" << price << "\t" << publishDate;
    }
}

void DbManager::updateBooksPrice(const int id, const int price)
{
    QSqlQuery query;

    query.prepare("update Books set price = (:price) where id = (:id)");

    query.bindValue(":price", price);
    query.bindValue(":id", id);

    if(!query.exec()) {
        qDebug() << query.lastError().text();
        return;
    }

    if(query.numRowsAffected() != -1) {
        qDebug() << query.numRowsAffected() << " rows updated";
    }
}

void DbManager::deleteBook(const int id)
{
    QSqlQuery query;

    query.prepare("delete from Books where id = (:id)");

    query.bindValue(":id", id);

    if(!query.exec()) {
        qDebug() << query.lastError().text();
        return;
    }

    if(query.numRowsAffected() != -1) {
        qDebug() << query.numRowsAffected() << " rows deleted";
    }
}

void DbManager::deleteAllBooks()
{
    QSqlQuery query;

    if(!query.exec("delete from Books")) {
        qDebug() << query.lastError().text();
        return;
    }

    if(query.numRowsAffected() != -1) {
        qDebug() << query.numRowsAffected() << " rows deleted";
    }
}






