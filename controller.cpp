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
