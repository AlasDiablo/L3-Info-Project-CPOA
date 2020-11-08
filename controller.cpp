/**
 * @file controller.cpp
 * @brief Controller Class
 * @author Safyrus
 * @version 1.1
 */

#include "controller.h"
#include "mainwindow.h"
#include <iostream>

Controller::Controller(model::Data *data, MainWindow *window)
{
    this->data = data;
    this->window = window;
}

void Controller::createPC(std::string userName, std::string name)
{
    model::User *u = data->getUser(userName);
    if(u == nullptr)
    {
        return;
    }

    model::PC *pc = data->getPC(name);
    if(pc != nullptr)
    {
        return;
    }

    model::PC p(name, *u);
    data->addPC(p);
    window->refresh();
}

void Controller::createUser(std::string name)
{
    model::User *u = data->getUser(name);
    if(u != nullptr)
    {
        return;
    }
    model::User user(name);
    data->addUser(user);
    window->refresh();
}

void Controller::changeUser(std::string name, std::string newName)
{
    data->removeUser(name);
    createUser(newName);

    model::User newUser = *data->getUser(newName);
    for (unsigned int i=0; i<data->getPCSize(); i++) {
        if(data->getPC(i)->getCreatorName().compare(name)==0)
        {
            std::string pcName = data->getPC(i)->getName();
            data->removePC(i);
            model::PC tmp(pcName, newUser);
            data->addPC(tmp);
        }
    }
    window->refresh();
}

void Controller::changePC(std::string name, std::string newName)
{
    model::PC pc = *data->getPC(name);
    data->removePC(name);
    model::PC newPC(newName, *data->getUser(pc.getCreatorName()));
    data->addPC(newPC);
    window->refresh();
}
