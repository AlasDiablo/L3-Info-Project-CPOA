/**
 * @file mainwindow.cpp
 * @brief MainWindow Class
 * @author Safyrus
 * @version 1.7
 */

#include "mainwindow.h"
#include "controller.h"

#include <QCoreApplication>

#include <string>
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    // creer les donnees et les controlleurs
    data = new model::DataDB();
    ctrl = new Controller(data, this);
    ctrlPC = new ControllerPC(data, this);

    // change la taille de la fenetre
    resize(1280, 720);

    // créer tout les element de la fenetre
    createInterfacePC();
    createInterfaceProd();
    createInterfaceProduct();
    createInterfaceUser();
    createInterfaceAdmin();
    createInterfaceList();
    createInterfaceOther();

    // actualise la fenetre
    refresh();
}

MainWindow::~MainWindow()
{
    // detruit les element de la fenetre
    deleteButtons();
    deleteLineEdits();
    deleteLabels();

    // detruit les donnees
    if(data != nullptr)
    {
        delete data;
    }

    // detruit les controlleur
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
    // creer les boutons
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

    // connect les boutons avec les handlers correspondant
    connect(b_CreatePC, SIGNAL (released()), this, SLOT (handlerCreatePC()));
    connect(b_ChangePC, SIGNAL (released()), this, SLOT (handlerChangePC()));
    connect(b_DeletePC, SIGNAL (released()), this, SLOT (handlerDeletePC()));
    connect(b_CheckPC, SIGNAL (released()), this, SLOT (handlerCheckPC()));
    connect(b_OpenPC, SIGNAL (released()), this, SLOT (handlerOpenPC()));

    // creer les champs de texte
    le_PCName = new QLineEdit(this);
    le_PCName->setGeometry(10, 20, 100, 30);
    le_PCNewName = new QLineEdit(this);
    le_PCNewName->setGeometry(120, 20, 100, 30);

    // creer les labels
    l_PCName = new QLabel(this);
    l_PCName->setGeometry(10, 10, 100, 10);
    l_PCName->setText("Nom PC");
    l_PCNewName = new QLabel(this);
    l_PCNewName->setGeometry(120, 10, 100, 10);
    l_PCNewName->setText("Nouveau Nom PC");
}

void MainWindow::createInterfaceUser()
{
    // creer les boutons
    b_CreateUser = new QPushButton("create User", this);
    b_CreateUser->setGeometry(300, 80, 100, 30);
    b_ChangeUser = new QPushButton("change User", this);
    b_ChangeUser->setGeometry(410, 80, 100, 30);
    b_DeleteUser = new QPushButton("delete User", this);
    b_DeleteUser->setGeometry(520, 80, 100, 30);

    // connect les boutons avec les handlers correspondant
    connect(b_CreateUser, SIGNAL (released()), this, SLOT (handlerCreateUser()));
    connect(b_ChangeUser, SIGNAL (released()), this, SLOT (handlerChangeUser()));
    connect(b_DeleteUser, SIGNAL (released()), this, SLOT (handlerDeleteUser()));

    // creer les champs de texte
    le_UserName = new QLineEdit(this);
    le_UserName->setGeometry(10, 80, 100, 30);
    le_UserNewName = new QLineEdit(this);
    le_UserNewName->setGeometry(120, 80, 100, 30);

    // creer les labels
    l_UserName = new QLabel(this);
    l_UserName->setGeometry(10, 70, 100, 10);
    l_UserName->setText("Nom Utilisateur");
    l_UserNewName = new QLabel(this);
    l_UserNewName->setGeometry(120, 70, 100, 10);
    l_UserNewName->setText("Nouveau Nom");
}

void MainWindow::createInterfaceProd()
{
    // creer les boutons
    b_AddProdPC = new QPushButton("add Prod", this);
    b_AddProdPC->setGeometry(300, 140, 100, 30);
    b_RemoveProdPC = new QPushButton("remove Prod", this);
    b_RemoveProdPC->setGeometry(410, 140, 100, 30);

    // connect les boutons avec les handlers correspondant
    connect(b_AddProdPC, SIGNAL (released()), this, SLOT (handlerAddProdPC()));
    connect(b_RemoveProdPC, SIGNAL (released()), this, SLOT (handlerRemoveProdPC()));

    // creer les champs de texte
    le_ProdName = new QLineEdit(this);
    le_ProdName->setGeometry(10, 140, 100, 30);

    // creer les labels
    l_ProdName = new QLabel(this);
    l_ProdName->setGeometry(10, 130, 100, 10);
    l_ProdName->setText("Nom Producteur");
}

void MainWindow::createInterfaceProduct()
{
    // creer les boutons
    b_AddProduct = new QPushButton("add product", this);
    b_AddProduct->setGeometry(300, 200, 100, 30);
    b_RemoveProduct = new QPushButton("remove product", this);
    b_RemoveProduct->setGeometry(410, 200, 100, 30);
    b_ChangePriceProduct = new QPushButton("change price", this);
    b_ChangePriceProduct->setGeometry(520, 200, 100, 30);
    b_ChangeNameProduct = new QPushButton("change name", this);
    b_ChangeNameProduct->setGeometry(630, 200, 100, 30);

    // connect les boutons avec les handlers correspondant
    connect(b_AddProduct, SIGNAL (released()), this, SLOT (handlerAddProduct()));
    connect(b_RemoveProduct, SIGNAL (released()), this, SLOT (handlerRemoveProduct()));
    connect(b_ChangePriceProduct, SIGNAL (released()), this, SLOT (handlerChangePriceProduct()));
    connect(b_ChangeNameProduct, SIGNAL (released()), this, SLOT (handlerChangeNameProduct()));

    // creer les champs de texte
    le_ProductName = new QLineEdit(this);
    le_ProductName->setGeometry(10, 200, 100, 30);
    le_ProductChange = new QLineEdit(this);
    le_ProductChange->setGeometry(120, 200, 100, 30);

    // creer les labels
    l_ProductName = new QLabel(this);
    l_ProductName->setGeometry(10, 190, 100, 10);
    l_ProductName->setText("Nom Produit");
    l_ProductChange = new QLabel(this);
    l_ProductChange->setGeometry(120, 190, 100, 10);
    l_ProductChange->setText("Changement Produit");
}

void MainWindow::createInterfaceAdmin()
{
    // creer les boutons
    b_CreateAdmin = new QPushButton("create Admin", this);
    b_CreateAdmin->setGeometry(300, 260, 100, 30);

    // connect les boutons avec les handlers correspondant
    connect(b_CreateAdmin, SIGNAL (released()), this, SLOT (handlerCreateAdmin()));

    // creer les champs de texte
    le_AdminName = new QLineEdit(this);
    le_AdminName->setGeometry(10, 260, 100, 30);

    // creer les labels
    l_AdminName = new QLabel(this);
    l_AdminName->setGeometry(10, 250, 100, 10);
    l_AdminName->setText("Nom Admin");
}

void MainWindow::createInterfaceList()
{
    // creer les labels
    l_users = new QLabel(this);
    l_users->setGeometry(10, 360, 200, 200);
    l_pcs = new QLabel(this);
    l_pcs->setGeometry(210, 360, 200, 200);
    l_productor = new QLabel(this);
    l_productor->setGeometry(420, 360, 200, 200);
    l_product = new QLabel(this);
    l_product->setGeometry(630, 360, 200, 200);
    l_orders = new QLabel(this);
    l_orders->setGeometry(840, 360, 200, 200);
    l_admins = new QLabel(this);
    l_admins->setGeometry(1050, 360, 200, 200);
}

void MainWindow::createInterfaceOther()
{
    b_Order = new QPushButton("order", this);
    b_Order->setGeometry(300, 320, 100, 30);

    connect(b_Order, SIGNAL (released()), this, SLOT (handlerOrder()));
}

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
    if(b_OpenPC != nullptr)
    {
        delete b_OpenPC;
    }
}

void MainWindow::deleteLabels()
{
    if(l_AdminName != nullptr)
    {
        delete l_AdminName;
    }
    if(l_PCName != nullptr)
    {
        delete l_PCName;
    }
    if(l_PCNewName != nullptr)
    {
        delete l_PCNewName;
    }
    if(l_ProdName != nullptr)
    {
        delete l_ProdName;
    }
    if(l_ProductChange != nullptr)
    {
        delete l_ProductChange;
    }
    if(l_ProductName != nullptr)
    {
        delete l_ProductName;
    }
    if(l_UserName != nullptr)
    {
        delete l_UserName;
    }
    if(l_UserNewName != nullptr)
    {
        delete l_UserNewName;
    }

    if(l_admins != nullptr)
    {
        delete l_admins;
    }
    if(l_orders != nullptr)
    {
        delete l_orders;
    }
    if(l_pcs != nullptr)
    {
        delete l_pcs;
    }
    if(l_product != nullptr)
    {
        delete l_product;
    }
    if(l_productor != nullptr)
    {
        delete l_productor;
    }
    if(l_users != nullptr)
    {
        delete l_users;
    }
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
    QString pcName = le_PCName->text();
    QString product = le_ProductName->text();
    QString user = le_UserName->text();
    ctrl->order(pcName, product, user);
}

void MainWindow::handlerOpenPC()
{
    QString pc = le_PCName->text();
    QString user = le_UserName->text();

    ctrlPC->openPC(pc, user);
}

void MainWindow::refresh()
{
    QString qs = "Utilistaeurs:\n";
    QString prds = "Producteurs:\n";
    QString prducts = "Produits:\n";

    // recupere les donnees a afficher
    std::vector<model::User> users = data->getUsers();
    int size = users.size();
    // pour chaque utilisateur on ajoute ses information a qs
    for (int i=0; i<size; i++) {
        model::User u = users.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += u.getName();
        qs += '\n';
    }
    // affiche les donnees
    l_users->setText(qs);


    // recupere les donnees a afficher
    qs = "PCs:\n";
    std::vector<model::PC> pcs = data->getPCs();
    size = pcs.size();
    // pour chaque pc on ajoute ses information a qs
    for (int i=0; i<size; i++) {
        model::PC pc = pcs.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += ": ";
        qs += pc.getName();
        qs += "(";
        qs += pc.getCreatorName();
        qs += ") ";
        qs += (pc.getCheck())?"check":"not check";
        qs += ", ";
        qs += (pc.getOpen())?"open":"not open";
        qs += "\n";
        std::vector<model::Productor> productors = data->getProductors(pc);
        for (unsigned int j=0; j<productors.size(); j++) {
            prds += std::to_string(j).c_str();
            prds += ": ";
            prds += productors[j].getName();
            prds += "(";
            prds += pc.getName();
            prds += ")\n";
        }
        std::vector<model::Product> prods = data->getProducts(pc);
        for (unsigned int j=0; j<prods.size(); j++) {
            prducts += std::to_string(j).c_str();
            prducts += ": ";
            prducts += prods[j].getName();
            prducts += "(";
            prducts += pc.getName();
            prducts += ", ";
            prducts += prods[j].getProductorName();
            prducts += "):";
            prducts += std::to_string(prods[j].getPrice()).c_str();
            prducts += "\n";
        }
    }
    // affiche les donnees
    l_pcs->setText(qs);
    l_productor->setText(prds);
    l_product->setText(prducts);


    // recupere les donnees a afficher
    qs = "Admins:\n";
    std::vector<model::Admin> admins = data->getAdmins();
    size = admins.size();
    // pour chaque Admin  on ajoute ses information a qs
    for (int i=0; i<size; i++) {
        model::Admin admin = admins.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += admin.getName();
        qs += '\n';
    }
    // affiche les donnees
    l_admins->setText(qs);

    qs = "Commands:\n";
    std::vector<model::Order> orders = data->getOrders();
    size = orders.size();
    for (int i=0; i<size; i++) {
        model::Order order = orders.at(i);
        qs += std::to_string(i).c_str();
        qs += ": ";
        qs += order.getUser().getName();
        qs += ", ";
        qs += order.getPC().getName();
        qs += ", ";
        qs += order.getProduct().getName();
        qs += "\n";
    }
    l_orders->setText(qs);
}
