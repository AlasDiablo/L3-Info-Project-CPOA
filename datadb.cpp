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

        QSqlQuery enableForeignKey("PRAGMA foreign_keys = ON");
        if(!enableForeignKey.isActive())
            qWarning() << "ERROR: " << enableForeignKey.lastError().text();

        QSqlQuery createUser("create table if not exists `user`(name text, primary key (name))");
        if(!createUser.isActive())
            qWarning() << "ERROR: " << createUser.lastError().text();

        QSqlQuery createAdmin("create table if not exists admin(name text, primary key (name))");
        if(!createAdmin.isActive())
            qWarning() << "ERROR: " << createAdmin.lastError().text();

        QSqlQuery createPC("create table if not exists pc(name text, author text, `check` integer, primary key (name), foreign key (author) references user (name) on delete cascade on update cascade)");
        if(!createPC.isActive())
            qWarning() << "ERROR: " << createPC.lastError().text();

        QSqlQuery createProductor("create table if not exists productor(name text, pc_name text, primary key (name), foreign key (pc_name) references pc (name) on delete cascade on update cascade)");
        if(!createProductor.isActive())
            qWarning() << "ERROR: " << createProductor.lastError().text();

        QSqlQuery createProduct("create table if not exists product(name text, price real, pc_name text, productor_name text, primary key (name), foreign key (pc_name) references pc (name) on delete cascade on update cascade, foreign key (productor_name) references productor(name) on delete cascade on update cascade)");
        if(!createProduct.isActive())
            qWarning() << "ERROR: " << createProduct.lastError().text();

    } else {
        throw "Driver not found !";
    }
}

unsigned int model::DataDB::getUserSize()
{
    QSqlQuery query;
    query.prepare("select count(name) from `user` group by name");
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
    while (query.next()) {
         return query.value(0).toInt();
    }
    return -1;
}

model::User model::DataDB::getUser(QString name)
{
    QSqlQuery query;
    query.prepare("select name from `user` where name like ?");
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
    while (query.next()) {
         model::User u(query.value(0).toString());
         return u;
    }
    model::User err("ERROR");
    return err;
}

std::vector<model::User> model::DataDB::getUsers()
{
    QSqlQuery query;
    query.prepare("select * from `user`");
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    std::vector<model::User> users;
    while (query.next()) {
        User u(query.value(0).toString());
        users.push_back(u);
    }
    return users;
}

unsigned int model::DataDB::getPCSize()
{
    QSqlQuery query;
    query.prepare("select count(name) from pc group by name");
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
    while (query.next()) {
         return query.value(0).toInt();
    }
    return -1;
}

model::PC model::DataDB::getPC(QString name)
{
    QSqlQuery query;
    query.prepare("select name, author, `check` from pc where name like ?");
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
    while (query.next()) {
         model::User qauthor(query.value(1).toString());
         model::PC pc(query.value(0).toString(), qauthor);
         pc.setCheck(query.value(2).toInt() == 0 ? true : false);
         return pc;
    }
    model::User errU("ERROR");
    model::PC err("ERROR", errU);
    return err;
}

std::vector<model::PC> model::DataDB::getPCs()
{
    QSqlQuery query;
    query.prepare("select * from pc");
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    std::vector<model::PC> pcs;
    while (query.next()) {
        User u(query.value(1).toString());
        PC pc(query.value(0).toString(), u);
        pc.setCheck(query.value(2).toInt() == 0 ? true : false);
        pcs.push_back(pc);
    }
    return pcs;
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
    if(p.getName().compare("ERROR")==0)
    {
        return;
    }
    QSqlQuery query;
    query.prepare("insert into pc values(?, ?, ?)");
    query.addBindValue(p.getName());
    query.addBindValue(p.getCreatorName());
    query.addBindValue(p.getCheck() ? 0 : 1);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::removeUser(QString name)
{
    QSqlQuery query;
    query.prepare("delete from `user` where name=?");
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::removePC(QString name)
{
    QSqlQuery query;
    query.prepare("delete from pc where name=?");
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::addAdmin(model::Admin a)
{
    if(a.getName().compare("ERROR")==0)
    {
        return;
    }
    QSqlQuery query;
    query.prepare("insert into admin values(?)");
    query.addBindValue(a.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::removeAdmin(QString name)
{
    QSqlQuery query;
    query.prepare("delete from admin where name=?");
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

model::Admin model::DataDB::getAdmin(QString name)
{
    QSqlQuery query;
    query.prepare("select name from admin where name like ?");
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
    while (query.next()) {
         model::Admin a(query.value(0).toString());
         return a;
    }
    model::Admin err("ERROR");
    return err;
}

std::vector<model::Admin> model::DataDB::getAdmins()
{
    QSqlQuery query;
    query.prepare("select * from admin");
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    std::vector<model::Admin> admins;
    while (query.next()) {
        Admin a(query.value(0).toString());
        admins.push_back(a);
    }
    return admins;
}

void model::DataDB::changeUser(QString name, QString newName)
{
    QSqlQuery query;
    query.prepare("update `user` set name=? where name=?");
    query.addBindValue(newName);
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::changePC(QString name, model::PC newPC)
{
    QSqlQuery query;
    query.prepare("update pc set name=?, `check`=? where name=?");
    query.addBindValue(newPC.getName());
    query.addBindValue(newPC.getCheck() ? 0 : 1);
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::changeAdmin(QString name, QString newName)
{
    QSqlQuery query;
    query.prepare("update admin set name=? where name=?");
    query.addBindValue(newName);
    query.addBindValue(name);
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}


void model::DataDB::addProductor(model::PC pc, model::Productor productor)
{
    if(pc.getName().compare("ERROR")==0)
    {
        return;
    }
    QSqlQuery query;
    query.prepare("insert into productor values(?, ?)");
    query.addBindValue(productor.getName());
    query.addBindValue(pc.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::removeProductor(model::PC pc, model::Productor productor)
{
    QSqlQuery query;
    query.prepare("delete from productor where name=? and pc_name=?");
    query.addBindValue(productor.getName());
    query.addBindValue(pc.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}


void model::DataDB::changeProductor(model::PC pc, model::Productor productor, model::Productor newProductor)
{
    QSqlQuery query;
    query.prepare("update productor set name=? where name=? and pc_name=?");
    query.addBindValue(newProductor.getName());
    query.addBindValue(productor.getName());
    query.addBindValue(pc.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

std::vector<model::Productor> model::DataDB::getProductors(model::PC pc)
{
    QSqlQuery query;
    query.prepare("select name from productor where pc_name=?");
    query.addBindValue(pc.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    std::vector<model::Productor> productors;
    while (query.next()) {
        Productor p(query.value(0).toString());
        productors.push_back(p);
    }
    return productors;
}



void model::DataDB::addProduct(model::PC pc, model::Product product)
{
    if(pc.getName().compare("ERROR")==0)
    {
        return;
    }
    QSqlQuery query;
    query.prepare("insert into product values(?, ?, ?, ?)");
    query.addBindValue(product.getName());
    query.addBindValue(product.getPrice());
    query.addBindValue(pc.getName());
    query.addBindValue(product.getProductorName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

void model::DataDB::removeProduct(model::PC pc, model::Product product)
{
    QSqlQuery query;
    query.prepare("delete from product where name=? and pc_name=? and productor_name=?");
    query.addBindValue(product.getName());
    query.addBindValue(pc.getName());
    query.addBindValue(product.getProductorName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}


void model::DataDB::changeProduct(model::PC pc, model::Product product, model::Product newProduct)
{
    QSqlQuery query;
    query.prepare("update productor set name=?, price=? where name=? and pc_name=? and productor_name=?");
    query.addBindValue(newProduct.getName());
    query.addBindValue(newProduct.getPrice());
    query.addBindValue(product.getName());
    query.addBindValue(pc.getName());
    query.addBindValue(product.getProductorName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();
}

std::vector<model::Product> model::DataDB::getProducts(model::PC pc)
{
    QSqlQuery query;
    query.prepare("select * from product where pc_name=?");
    query.addBindValue(pc.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    std::vector<model::Product> products;
    while (query.next()) {
        Product p(query.value(0).toString(), query.value(3).toString(), query.value(1).toFloat());
        products.push_back(p);
    }
    return products;
}

std::vector<model::Product> model::DataDB::getProducts(model::PC pc, model::Productor productor)
{
    QSqlQuery query;
    query.prepare("select * from product where pc_name=? and productor_name=?");
    query.addBindValue(pc.getName());
    query.addBindValue(productor.getName());
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    std::vector<model::Product> products;
    while (query.next()) {
        Product p(query.value(0).toString(), productor.getName(), query.value(1).toFloat());
        products.push_back(p);
    }
    return products;
}



