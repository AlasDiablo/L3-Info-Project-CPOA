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
    data = new model::DataDB();
    ctrl = new Controller(data, this);
    ctrlPC = new ControllerPC(data, this);

    resize(900, 500);

    createInterfacePC();
    createInterfaceProd();
    createInterfaceProduct();
    createInterfaceUser();
    createInterfaceAdmin();
    createInterfaceList();

    refresh();
}

MainWindow::~MainWindow()
{
    deleteButtons();
    deleteLineEdits();

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

void MainWindow::createInterfacePC()
{
    b_CreatePC = new QPushButton("create PC", this);
    b_CreatePC->setGeometry(300, 20, 100, 30);
    b_ChangePC = new QPushButton("change PC", this);
    b_ChangePC->setGeometry(410, 20, 100, 30);
    b_DeletePC = new QPushButton("delete PC", this);
    b_DeletePC->setGeometry(520, 20, 100, 30);
    b_CheckPC = new QPushButton("check PC", this);
    b_CheckPC->setGeometry(630, 20, 100, 30);
    b_OpenPC = new QPushButton("openPC", this);
    b_OpenPC->setGeometry(740, 20, 100, 30);

    connect(b_CreatePC, SIGNAL (released()), this, SLOT (handlerCreatePC()));
    connect(b_ChangePC, SIGNAL (released()), this, SLOT (handlerChangePC()));
    connect(b_DeletePC, SIGNAL (released()), this, SLOT (handlerDeletePC()));
    connect(b_CheckPC, SIGNAL (released()), this, SLOT (handlerCheckPC()));
    connect(b_OpenPC, SIGNAL (released()), this, SLOT (handlerOpenPC()));

    le_PCName = new QLineEdit(this);
    le_PCName->setGeometry(10, 20, 100, 30);
    le_PCNewName = new QLineEdit(this);
    le_PCNewName->setGeometry(120, 20, 100, 30);

    l_PCName = new QLabel(this);
    l_PCName->setGeometry(10, 10, 100, 10);
    l_PCName->setText("Nom PC");
    l_PCNewName = new QLabel(this);
    l_PCNewName->setGeometry(120, 10, 100, 10);
    l_PCNewName->setText("Nouveau Nom PC");
}

void MainWindow::createInterfaceUser()
{
    b_CreateUser = new QPushButton("create User", this);
    b_CreateUser->setGeometry(300, 80, 100, 30);
    b_ChangeUser = new QPushButton("change User", this);
    b_ChangeUser->setGeometry(410, 80, 100, 30);
    b_DeleteUser = new QPushButton("delete User", this);
    b_DeleteUser->setGeometry(520, 80, 100, 30);

    connect(b_CreateUser, SIGNAL (released()), this, SLOT (handlerCreateUser()));
    connect(b_ChangeUser, SIGNAL (released()), this, SLOT (handlerChangeUser()));
    connect(b_DeleteUser, SIGNAL (released()), this, SLOT (handlerDeleteUser()));

    le_UserName = new QLineEdit(this);
    le_UserName->setGeometry(10, 80, 100, 30);
    le_UserNewName = new QLineEdit(this);
    le_UserNewName->setGeometry(120, 80, 100, 30);

    l_UserName = new QLabel(this);
    l_UserName->setGeometry(10, 70, 100, 10);
    l_UserName->setText("Nom Utilisateur");
    l_UserNewName = new QLabel(this);
    l_UserNewName->setGeometry(120, 70, 100, 10);
    l_UserNewName->setText("Nouveau Nom");
}

void MainWindow::createInterfaceProd()
{
    b_AddProdPC = new QPushButton("add Prod", this);
    b_AddProdPC->setGeometry(300, 140, 100, 30);
    b_RemoveProdPC = new QPushButton("remove Prod", this);
    b_RemoveProdPC->setGeometry(410, 140, 100, 30);

    connect(b_AddProdPC, SIGNAL (released()), this, SLOT (handlerAddProdPC()));
    connect(b_RemoveProdPC, SIGNAL (released()), this, SLOT (handlerRemoveProdPC()));

    le_ProdName = new QLineEdit(this);
    le_ProdName->setGeometry(10, 140, 100, 30);

    l_ProdName = new QLabel(this);
    l_ProdName->setGeometry(10, 130, 100, 10);
    l_ProdName->setText("Nom Producteur");
}

void MainWindow::createInterfaceProduct()
{
    b_AddProduct = new QPushButton("add product", this);
    b_AddProduct->setGeometry(300, 200, 100, 30);
    b_RemoveProduct = new QPushButton("remove product", this);
    b_RemoveProduct->setGeometry(410, 200, 100, 30);
    b_ChangePriceProduct = new QPushButton("change price", this);
    b_ChangePriceProduct->setGeometry(520, 200, 100, 30);
    b_ChangeNameProduct = new QPushButton("change name", this);
    b_ChangeNameProduct->setGeometry(630, 200, 100, 30);

    connect(b_AddProduct, SIGNAL (released()), this, SLOT (handlerAddProduct()));
    connect(b_RemoveProduct, SIGNAL (released()), this, SLOT (handlerRemoveProduct()));
    connect(b_ChangePriceProduct, SIGNAL (released()), this, SLOT (handlerChangePriceProduct()));
    connect(b_ChangeNameProduct, SIGNAL (released()), this, SLOT (handlerChangeNameProduct()));

    le_ProductName = new QLineEdit(this);
    le_ProductName->setGeometry(10, 200, 100, 30);
    le_ProductChange = new QLineEdit(this);
    le_ProductChange->setGeometry(120, 200, 100, 30);

    l_ProductName = new QLabel(this);
    l_ProductName->setGeometry(10, 190, 100, 10);
    l_ProductName->setText("Nom Produit");
    l_ProductChange = new QLabel(this);
    l_ProductChange->setGeometry(120, 190, 100, 10);
    l_ProductChange->setText("Changement Produit");
}

void MainWindow::createInterfaceAdmin()
{
    b_CreateAdmin = new QPushButton("create Admin", this);
    b_CreateAdmin->setGeometry(300, 260, 100, 30);

    connect(b_CreateAdmin, SIGNAL (released()), this, SLOT (handlerCreateAdmin()));

    le_AdminName = new QLineEdit(this);
    le_AdminName->setGeometry(10, 260, 100, 30);

    l_AdminName = new QLabel(this);
    l_AdminName->setGeometry(10, 250, 100, 10);
    l_AdminName->setText("Nom Admin");
}

void MainWindow::createInterfaceList()
{
    l_pcs = new QLabel(this);
    l_pcs->setGeometry(10, 300, 200, 200);
    l_users = new QLabel(this);
    l_users->setGeometry(210, 300, 200, 200);
    l_admins = new QLabel(this);
    l_admins->setGeometry(410, 300, 200, 200);
    l_orders = new QLabel(this);
    l_orders->setGeometry(610, 300, 200, 200);
}

/*
void MainWindow::createButtons()
{
    b_Order = new QPushButton("order", this);
    b_Order->setGeometry(200, 160, 100, 30);
    b_Deliver = new QPushButton("deliver", this);
    b_Deliver->setGeometry(310, 160, 100, 30);
    b_CheckDelivery = new QPushButton("checkDelivery", this);
    b_CheckDelivery->setGeometry(420, 160, 100, 30);

    connect(b_Order, SIGNAL (released()), this, SLOT (handlerOrder()));
    connect(b_Deliver, SIGNAL (released()), this, SLOT (handlerDeliver()));
    connect(b_CheckDelivery, SIGNAL (released()), this, SLOT (handlerCheckDelivery()));
}
*/

void MainWindow::deleteLineEdits()
{
    if(le_PCName != nullptr)
    {
        delete le_PCName;
    }
    if(le_PCNewName != nullptr)
    {
        delete le_PCNewName;
    }
    if(le_AdminName != nullptr)
    {
        delete le_AdminName;
    }
    if(le_ProdName != nullptr)
    {
        delete le_ProdName;
    }
    if(le_ProductChange != nullptr)
    {
        delete le_ProductChange;
    }
    if(le_ProductName != nullptr)
    {
        delete le_ProductName;
    }
    if(le_UserName != nullptr)
    {
        delete le_UserName;
    }
    if(le_UserNewName != nullptr)
    {
        delete le_UserNewName;
    }
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
    if(b_DeleteUser != nullptr)
    {
        delete b_DeleteUser;
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
    if(b_Order != nullptr)
    {
        delete b_Order;
    }
    if(b_Deliver != nullptr)
    {
        delete b_Deliver;
    }
    if(b_CheckDelivery != nullptr)
    {
        delete b_CheckDelivery;
    }
    if(b_OpenPC != nullptr)
    {
        delete b_OpenPC;
    }
}

void MainWindow::deleteLabels()
{

}

void MainWindow::handlerCreateUser()
{
    QString userName = le_UserName->text();
    ctrl->createUser(userName);
}

void MainWindow::handlerCreatePC()
{
    QString name = le_PCName->text();
    QString userName = le_UserName->text();
    ctrlPC->createPC(userName, name);
}

void MainWindow::handlerChangeUser()
{
    QString name = le_UserName->text();
    QString newName = le_UserNewName->text();
    ctrl->changeUser(name, newName);
}

void MainWindow::handlerChangePC()
{
    QString name = le_PCName->text();
    QString newName = le_PCNewName->text();
    ctrlPC->changePC(name, newName);
}

void MainWindow::handlerDeleteUser()
{
    QString name = le_UserName->text();
    ctrl->deleteUser(name);
}

void MainWindow::handlerDeletePC()
{
    QString name = le_PCName->text();
    ctrlPC->deletePC(name);
}

void MainWindow::handlerCreateAdmin()
{
    QString name = le_AdminName->text();
    ctrl->createAdmin(name);
}

void MainWindow::handlerCheckPC()
{
    QString pc = le_PCName->text();
    QString admin = le_AdminName->text();
    ctrlPC->checkPC(pc, admin);
}

void MainWindow::handlerAddProdPC()
{
    QString pc = le_PCName->text();
    QString prod = le_ProdName->text();
    ctrlPC->addProductor(pc, prod);
}

void MainWindow::handlerRemoveProdPC()
{
    QString pc = le_PCName->text();
    QString prod = le_ProdName->text();
    ctrlPC->removeProductor(pc, prod);
}

void MainWindow::handlerAddProduct()
{
    QString name = le_ProductName->text();
    QString prodName = le_ProdName->text();
    QString pcName = le_PCName->text();
    ctrlPC->addProduct(name, prodName, pcName);
}

void MainWindow::handlerRemoveProduct()
{
    QString name = le_ProductName->text();
    QString prodName = le_ProdName->text();
    QString pcName = le_PCName->text();
    ctrlPC->removeProduct(name, prodName, pcName);
}

void MainWindow::handlerChangePriceProduct()
{
    QString name = le_ProductName->text();
    QString prodName = le_ProdName->text();
    QString pcName = le_PCName->text();
    QString qtName = le_ProductChange->text();
    std::string price = qtName.toUtf8().constData();
    try {
        ctrlPC->changeProductPrice(std::stof(price), name, prodName, pcName);
    }  catch (...) {

    }
}

void MainWindow::handlerChangeNameProduct()
{
    QString name = le_ProductName->text();
    QString prodName = le_ProdName->text();
    QString pcName = le_PCName->text();
    QString newName = le_ProductChange->text();
    ctrlPC->changeProductName(name, newName, prodName, pcName);
}

void MainWindow::handlerOrder()
{

}

void MainWindow::handlerDeliver()
{

}

void MainWindow::handlerCheckDelivery()
{

}

void MainWindow::handlerOpenPC()
{
    QString pc = le_PCName->text();
    QString user = le_UserName->text();
    ctrlPC->openPC(pc, user);
}

void MainWindow::refresh()
{
    QString qs = "";
    std::vector<model::User> users = data->getUsers();
    int size = users.size();
    for (int i=0; i<size; i++) {
        model::User u = users.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += u.getName();
        qs += '\n';
    }
    l_users->setText(qs);


    qs = "";
    std::vector<model::PC> pcs = data->getPCs();
    size = pcs.size();
    for (int i=0; i<size; i++) {
        model::PC pc = pcs.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += pc.getName();
        qs += ", ";
        qs += pc.getCreatorName();
        qs += ", ";
        qs += (pc.getCheck())?"check":"not check";
        qs += ", ";
        qs += (pc.getOpen())?"open":"not open";
        qs += "\n(";
        std::vector<model::Productor> productors = data->getProductors(pc);
        for (unsigned int i=0; i<productors.size(); i++) {
            qs += productors[i].getName();
            qs += " ";
        }
        qs += ")";
        qs += "(";
        std::vector<model::Product> prods = data->getProducts(pc);
        for (unsigned int i=0; i<prods.size(); i++) {
            qs += prods[i].getName();
            qs += ":";
            qs += std::to_string(prods[i].getPrice()).c_str();
            qs += "  ";
        }
        qs += ")";
        qs += '\n';
    }
    l_pcs->setText(qs);

    qs = "";

    std::vector<model::Admin> admins = data->getAdmins();
    size = admins.size();
    for (int i=0; i<size; i++) {
        model::Admin admin = admins.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += admin.getName();
        qs += '\n';
    }
    l_admins->setText(qs);
}
