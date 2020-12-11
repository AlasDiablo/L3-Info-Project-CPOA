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
    /*
    data->removeUser(name);
    createUser(newName);

    model::User newUser = *data->getUser(newName);
    for (unsigned int i=0; i<data->getPCSize(); i++) {
        if(data->getPC(i)->getCreatorName().compare(name)==0)
        {
            QString pcName = data->getPC(i)->getName();
            data->removePC(i);
            model::PC tmp(pcName, newUser);
            data->addPC(tmp);
        }
    }
    window->refresh();
    */
}

void Controller::createAdmin(QString name)
{
    /*
    model::Admin *a = data->getAdmin(name);
    if(a != nullptr)
    {
        return;
    }
    model::Admin admin(name);
    data->addAdmin(admin);

    window->refresh();
    */
}

void Controller::checkPC(QString pc, QString admin)
{
    /*
    model::Admin *a = data->getAdmin(admin);
    if(a == nullptr)
    {
        return;
    }

    model::PC *p = data->getPC(pc);
    p->setCheck(!p->getCheck());
    window->refresh();
    */
}
