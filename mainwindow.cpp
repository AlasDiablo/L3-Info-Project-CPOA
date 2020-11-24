/**
 * @file mainwindow.cpp
 * @brief MainWindow Class
 * @author Safyrus
 * @version 1.2
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

    b_CreatePC = new QPushButton("create PC", this);
    b_CreatePC->setGeometry(10, 10, 100, 30);
    b_CreateUser = new QPushButton("create User", this);
    b_CreateUser->setGeometry(10, 40, 100, 30);
    b_ChangeUser = new QPushButton("change User", this);
    b_ChangeUser->setGeometry(340, 40, 100, 30);
    b_ChangePC = new QPushButton("change PC", this);
    b_ChangePC->setGeometry(340, 10, 100, 30);
    b_DeletePC = new QPushButton("delete PC", this);
    b_DeletePC->setGeometry(10, 70, 100, 30);
    b_CreateAdmin = new QPushButton("create Admin", this);
    b_CreateAdmin->setGeometry(340, 70, 100, 30);

    connect(b_CreatePC, SIGNAL (released()), this, SLOT (handlerCreatePC()));
    connect(b_CreateUser, SIGNAL (released()), this, SLOT (handlerCreateUser()));
    connect(b_ChangeUser, SIGNAL (released()), this, SLOT (handlerChangeUser()));
    connect(b_ChangePC, SIGNAL (released()), this, SLOT (handlerChangePC()));
    connect(b_DeletePC, SIGNAL (released()), this, SLOT (handlerDeletePC()));
    connect(b_CreateAdmin, SIGNAL (released()), this, SLOT (handlerCreateAdmin()));

    le_UserName = new QLineEdit(this);
    le_UserName->setGeometry(120, 40, 100, 30);
    le_PCName = new QLineEdit(this);
    le_PCName->setGeometry(120, 10, 100, 30);

    le_ChangeUserName = new QLineEdit(this);
    le_ChangeUserName->setGeometry(230, 40, 100, 30);
    le_ChangePCName = new QLineEdit(this);
    le_ChangePCName->setGeometry(230, 10, 100, 30);

    le_AdminName = new QLineEdit(this);
    le_AdminName->setGeometry(230, 70, 100, 30);

    l_pcs = new QLabel(this);
    l_pcs->setGeometry(10, 100, 240, 200);
    l_users = new QLabel(this);
    l_users->setGeometry(250, 100, 240, 200);
    l_admins = new QLabel(this);
    l_admins->setGeometry(490, 100, 240, 200);
}

MainWindow::~MainWindow()
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

    if(le_UserName != nullptr)
    {
        delete le_UserName;
    }
    if(le_PCName != nullptr)
    {
        delete le_PCName;
    }
    if(le_AdminName != nullptr)
    {
        delete le_AdminName;
    }
    if(le_ChangePCName != nullptr)
    {
        delete le_ChangePCName;
    }
    if(le_ChangeUserName != nullptr)
    {
        delete le_ChangeUserName;
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

void MainWindow::handlerCreateUser()
{
    QString userName = le_UserName->text();
    std::string userNameStr = userName.toUtf8().constData();
    ctrl->createUser(userNameStr);
}

void MainWindow::handlerCreatePC()
{
    QString userName = le_UserName->text();
    std::string userNameStr = userName.toUtf8().constData();
    QString name = le_PCName->text();
    std::string nameStr = name.toUtf8().constData();
    ctrlPC->createPC(userNameStr, nameStr);
}

void MainWindow::handlerChangeUser()
{
    QString qtName = le_UserName->text();
    std::string name = qtName.toUtf8().constData();
    QString qtNewName = le_ChangeUserName->text();
    std::string newName = qtNewName.toUtf8().constData();
    ctrl->changeUser(name, newName);
}

void MainWindow::handlerChangePC()
{
    QString qtName = le_PCName->text();
    std::string name = qtName.toUtf8().constData();
    QString qtNewName = le_ChangePCName->text();
    std::string newName = qtNewName.toUtf8().constData();
    ctrlPC->changePC(name, newName);
}

void MainWindow::handlerDeletePC()
{
    QString qtName = le_PCName->text();
    std::string name = qtName.toUtf8().constData();
    ctrlPC->deletePC(name);
}

void MainWindow::handlerCreateAdmin()
{
    QString qtName = le_AdminName->text();
    std::string name = qtName.toUtf8().constData();
    ctrl->createAdmin(name);
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
