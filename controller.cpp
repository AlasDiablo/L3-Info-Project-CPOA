/**
 * @file controller.cpp
 * @brief Controller Class
 * @author Safyrus
 * @version 1.3
 */

#include "controller.h"
#include "mainwindow.h"
#include <iostream>

Controller::Controller(model::DataDB *data, MainWindow *window)
{
    this->data = data;
    this->window = window;
}

void Controller::createUser(QString name)
{
    model::User u = data->getUser(name);
    if(u.getName().compare("ERROR")!=0)
    {
        return;
    }
    model::User user(name);
    data->addUser(user);
    window->refresh();
}

void Controller::changeUser(QString name, QString newName)
{
    data->changeUser(name, newName);
    window->refresh();
}

void Controller::deleteUser(QString name)
{
    data->removeUser(name);
    window->refresh();
}

void Controller::createAdmin(QString name)
{
    model::Admin a = data->getAdmin(name);
    if(a.getName().compare("ERROR") != 0)
    {
        return;
    }
    model::Admin admin(name);
    data->addAdmin(admin);

    window->refresh();
}
