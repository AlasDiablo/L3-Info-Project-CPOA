/**
 * @file mainwindow.cpp
 * @brief MainWindow Class
 * @author Safyrus
 * @version 1.3
 */

#include "mainwindow.h"
#include "controller.h"

#include <QCoreApplication>

#include <string>
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    data = new model::Data();
    ctrl = new Controller(data, this);
    ctrlPC = new ControllerPC(data, this);

    resize(640, 400);

    createButtons();

    le_main = new QLineEdit(this);
    le_main->setGeometry(10, 10, 100, 30);
    le_change = new QLineEdit(this);
    le_change->setGeometry(10, 40, 100, 30);
    le_change2 = new QLineEdit(this);
    le_change2->setGeometry(10, 70, 100, 30);

    l_pcs = new QLabel(this);
    l_pcs->setGeometry(10, 170, 240, 150);
    l_users = new QLabel(this);
    l_users->setGeometry(170, 170, 240, 150);
    l_admins = new QLabel(this);
    l_admins->setGeometry(340, 170, 240, 150);
}

MainWindow::~MainWindow()
{
    deleteButtons();
    if(le_main != nullptr)
    {
        delete le_main;
    }
    if(le_change != nullptr)
    {
        delete le_change;
    }

    if(data != nullptr)
    {
        delete data;
    }
    if(ctrl != nullptr)
    {
        delete ctrl;
    }
    if(ctrlPC != nullptr)
    {
        delete ctrlPC;
    }
}

void MainWindow::createButtons()
{
    b_CreatePC = new QPushButton("create PC", this);
    b_CreatePC->setGeometry(200, 10, 100, 30);
    b_CreateUser = new QPushButton("create User", this);
    b_CreateUser->setGeometry(200, 40, 100, 30);
    b_ChangeUser = new QPushButton("change User", this);
    b_ChangeUser->setGeometry(310, 40, 100, 30);
    b_ChangePC = new QPushButton("change PC", this);
    b_ChangePC->setGeometry(310, 10, 100, 30);
    b_DeletePC = new QPushButton("delete PC", this);
    b_DeletePC->setGeometry(420, 10, 100, 30);
    b_CreateAdmin = new QPushButton("create Admin", this);
    b_CreateAdmin->setGeometry(200, 70, 100, 30);
    b_CheckPC = new QPushButton("check PC", this);
    b_CheckPC->setGeometry(310, 70, 100, 30);
    b_AddProdPC = new QPushButton("add Prod", this);
    b_AddProdPC->setGeometry(200, 100, 100, 30);
    b_RemoveProdPC = new QPushButton("remove Prod", this);
    b_RemoveProdPC->setGeometry(310, 100, 100, 30);
    b_AddProduct = new QPushButton("add product", this);
    b_AddProduct->setGeometry(200, 130, 100, 30);
    b_RemoveProduct = new QPushButton("remove product", this);
    b_RemoveProduct->setGeometry(310, 130, 100, 30);
    b_ChangePriceProduct = new QPushButton("change price", this);
    b_ChangePriceProduct->setGeometry(420, 130, 100, 30);
    b_ChangeNameProduct = new QPushButton("change name", this);
    b_ChangeNameProduct->setGeometry(530, 130, 100, 30);

    connect(b_CreatePC, SIGNAL (released()), this, SLOT (handlerCreatePC()));
    connect(b_CreateUser, SIGNAL (released()), this, SLOT (handlerCreateUser()));
    connect(b_ChangeUser, SIGNAL (released()), this, SLOT (handlerChangeUser()));
    connect(b_ChangePC, SIGNAL (released()), this, SLOT (handlerChangePC()));
    connect(b_DeletePC, SIGNAL (released()), this, SLOT (handlerDeletePC()));
    connect(b_CreateAdmin, SIGNAL (released()), this, SLOT (handlerCreateAdmin()));
    connect(b_CheckPC, SIGNAL (released()), this, SLOT (handlerCheckPC()));
    connect(b_AddProdPC, SIGNAL (released()), this, SLOT (handlerAddProdPC()));
    connect(b_RemoveProdPC, SIGNAL (released()), this, SLOT (handlerRemoveProdPC()));
    connect(b_AddProduct, SIGNAL (released()), this, SLOT (handlerAddProduct()));
    connect(b_RemoveProduct, SIGNAL (released()), this, SLOT (handlerRemoveProduct()));
    connect(b_ChangePriceProduct, SIGNAL (released()), this, SLOT (handlerChangePriceProduct()));
    connect(b_ChangeNameProduct, SIGNAL (released()), this, SLOT (handlerChangeNameProduct()));
}

void MainWindow::deleteButtons()
{
    if(b_CreatePC != nullptr)
    {
        delete b_CreatePC;
    }
    if(b_CreateUser != nullptr)
    {
        delete b_CreateUser;
    }
    if(b_CreateAdmin != nullptr)
    {
        delete b_CreateAdmin;
    }
    if(b_ChangePC != nullptr)
    {
        delete b_ChangePC;
    }
    if(b_ChangeUser != nullptr)
    {
        delete b_ChangeUser;
    }
    if(b_DeletePC != nullptr)
    {
        delete b_DeletePC;
    }
    if(b_CheckPC != nullptr)
    {
        delete b_CheckPC;
    }
    if(b_AddProdPC != nullptr)
    {
        delete b_AddProdPC;
    }
    if(b_RemoveProdPC != nullptr)
    {
        delete b_RemoveProdPC;
    }
    if(b_AddProduct != nullptr)
    {
        delete b_AddProduct;
    }
    if(b_RemoveProduct != nullptr)
    {
        delete b_RemoveProduct;
    }
    if(b_ChangePriceProduct != nullptr)
    {
        delete b_ChangePriceProduct;
    }
    if(b_ChangeNameProduct != nullptr)
    {
        delete b_ChangeNameProduct;
    }
}

void MainWindow::handlerCreateUser()
{
    QString userName = le_main->text();
    std::string userNameStr = userName.toUtf8().constData();
    ctrl->createUser(userNameStr);
}

void MainWindow::handlerCreatePC()
{
    QString userName = le_change->text();
    std::string userNameStr = userName.toUtf8().constData();
    QString name = le_main->text();
    std::string nameStr = name.toUtf8().constData();
    ctrlPC->createPC(userNameStr, nameStr);
}

void MainWindow::handlerChangeUser()
{
    QString qtName = le_main->text();
    std::string name = qtName.toUtf8().constData();
    QString qtNewName = le_change->text();
    std::string newName = qtNewName.toUtf8().constData();
    ctrl->changeUser(name, newName);
}

void MainWindow::handlerChangePC()
{
    QString qtName = le_main->text();
    std::string name = qtName.toUtf8().constData();
    QString qtNewName = le_change->text();
    std::string newName = qtNewName.toUtf8().constData();
    ctrlPC->changePC(name, newName);
}

void MainWindow::handlerDeletePC()
{
    QString qtName = le_main->text();
    std::string name = qtName.toUtf8().constData();
    ctrlPC->deletePC(name);
}

void MainWindow::handlerCreateAdmin()
{
    QString qtName = le_main->text();
    std::string name = qtName.toUtf8().constData();
    ctrl->createAdmin(name);
}

void MainWindow::handlerCheckPC()
{
    QString qtName = le_change->text();
    std::string admin = qtName.toUtf8().constData();
    qtName = le_main->text();
    std::string pc = qtName.toUtf8().constData();
    ctrl->checkPC(pc, admin);
}

void MainWindow::handlerAddProdPC()
{
    QString qtName = le_main->text();
    std::string prod = qtName.toUtf8().constData();
    qtName = le_change->text();
    std::string pc = qtName.toUtf8().constData();
    ctrlPC->addProductor(pc, prod);
}

void MainWindow::handlerRemoveProdPC()
{
    QString qtName = le_main->text();
    std::string prod = qtName.toUtf8().constData();
    qtName = le_change->text();
    std::string pc = qtName.toUtf8().constData();
    ctrlPC->removeProductor(pc, prod);
}

void MainWindow::handlerAddProduct()
{
    QString qtName = le_main->text();
    std::string name = qtName.toUtf8().constData();
    qtName = le_change->text();
    std::string prodName = qtName.toUtf8().constData();
    qtName = le_change2->text();
    std::string pcName = qtName.toUtf8().constData();
    ctrlPC->addProduct(name, prodName, pcName);
}

void MainWindow::handlerRemoveProduct()
{

}

void MainWindow::handlerChangePriceProduct()
{

}

void MainWindow::handlerChangeNameProduct()
{

}

void MainWindow::refresh()
{
    QString qs = "";
    std::vector<model::User> users = data->getUser();
    int size = users.size();
    for (int i=0; i<size; i++) {
        model::User u = users.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += u.getName().c_str();
        qs += '\n';
    }
    l_users->setText(qs);

    qs = "";
    std::vector<model::PC> pcs = data->getPC();
    size = pcs.size();
    for (int i=0; i<size; i++) {
        model::PC pc = pcs.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += pc.getName().c_str();
        qs += ", ";
        qs += pc.getCreatorName().c_str();
        qs += ", ";
        qs += (pc.getCheck())?"check":"not check";
        qs += "(";
        std::vector<model::Productor> productors = pc.getProds();
        for (unsigned int i=0; i<productors.size(); i++) {
            qs += productors[i].getName().c_str();
            qs += " ";
        }
        qs += ")";
        qs += "(";
        std::vector<model::Product> prods = pc.getProducts();
        for (unsigned int i=0; i<prods.size(); i++) {
            qs += prods[i].getName().c_str();
            qs += " ";
        }
        qs += ")";
        qs += '\n';
    }
    l_pcs->setText(qs);

    qs = "";
    std::vector<model::Admin> admins = data->getAdmin();
    size = admins.size();
    for (int i=0; i<size; i++) {
        model::Admin admin = admins.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += admin.getName().c_str();
        qs += '\n';
    }
    l_admins->setText(qs);
}
