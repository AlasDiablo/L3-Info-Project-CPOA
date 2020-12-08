#include "datadb.h"
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>

model::DataDB::DataDB() {
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER)) {
        this->db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName("Data.db");
        if(!db.open())
            qWarning() << "ERROR: " << db.lastError();

        QSqlQuery createUser("create table if not exists `user`(name text, primary key (name))");
        if(!createUser.isActive())
            qWarning() << "ERROR: " << createUser.lastError().text();

        QSqlQuery createPC("create table if not exists pc(name text, author text, primary key (name), foreign key (author) references user (name))");
        if(!createPC.isActive())
            qWarning() << "ERROR: " << createPC.lastError().text();

        QSqlQuery createProductor("create table if not exists productor(name text, pc_name text, primary key (name), foreign key (pc_name) references pc (name))");
        if(!createProductor.isActive())
            qWarning() << "ERROR: " << createProductor.lastError().text();

        QSqlQuery createProduct("create table if not exists product(name text, price integer, pc_name text, productor_name text, primary key (name), foreign key (pc_name) references pc (name) foreign key (productor_name ) references productor(name))");
        if(!createProduct.isActive())
            qWarning() << "ERROR: " << createProduct.lastError().text();

    } else {
        throw "Driver not found !";
    }
}

void model::Data::addUser(User u)
{
    QSqlQuery query;
    query.prepare("insert into `user` values(?)");
    query.addBindValue(u.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}
