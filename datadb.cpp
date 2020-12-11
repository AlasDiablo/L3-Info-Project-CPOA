#include "datadb.h"
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
 #include <QSqlResult>

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

unsigned int model::DataDB::getUserSize()
{

}

model::User model::DataDB::getUser(int i)
{
}

model::User model::DataDB::getUser(QString name)
{
    QSqlQuery query;
    query.prepare("select name from 'user' where name like ?");
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
    while (query.next()) {
         QString name = query.value(0).toString();
         QString qname = name;
         model::User u(qname);
         return u;
    }
    model::User err("ERROR");
    return err;
}

std::vector<model::User> model::DataDB::getUser()
{
    QSqlQuery query;
    query.prepare("select * from 'user'");
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    std::vector<model::User> users;
    while (query.next()) {
        User u((QString)(query.value(0).toString()));
        users.push_back(u);
    }
    return users;
}

unsigned int model::DataDB::getPCSize()
{

}

model::PC model::DataDB::getPC(int i)
{

}

model::PC model::DataDB::getPC(QString name)
{

}

std::vector<model::PC> model::DataDB::getPC()
{

}

void model::DataDB::addUser(User u)
{
    if(u.getName().compare("ERROR")==0)
    {
        return;
    }
    QSqlQuery query;
    query.prepare("insert into `user` values(?)");
    query.addBindValue(u.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::addPC(PC p)
{

}

void model::DataDB::removeUser(QString name)
{

}

void model::DataDB::removePC(QString name)
{

}

void model::DataDB::removeUser(int i)
{

}

void model::DataDB::removePC(int i)
{

}

void model::DataDB::addAdmin(model::Admin a)
{

}

void model::DataDB::removeAdmin(QString name)
{

}

void model::DataDB::removeAdmin(int i)
{

}

model::Admin model::DataDB::getAdmin(int i)
{

}

model::Admin model::DataDB::getAdmin(QString name)
{

}

std::vector<model::Admin> model::DataDB::getAdmin()
{

}

