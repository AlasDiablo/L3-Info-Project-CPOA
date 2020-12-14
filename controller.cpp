/**
 * @file controller.cpp
 * @brief Controller Class
 * @author Safyrus
 * @version 1.7
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
    // vérifie si l'utilisateur n'existe pas déjà
    model::User u = data->getUser(name);
    if(u.getName().compare("ERROR")!=0)
    {
        return;
    }

    // ajout de l'utilisateur
    model::User user(name);
    data->addUser(user);

    // actualisation de la fenêtre
    window->refresh();
}

void Controller::changeUser(QString name, QString newName)
{
    data->changeUser(name, newName);

    // actualisation de la fenêtre
    window->refresh();
}

void Controller::deleteUser(QString name)
{
    data->removeUser(name);

    // actualisation de la fenêtre
    window->refresh();
}

void Controller::createAdmin(QString name)
{
    // vérifie si l'administrateur n'existe pas déjà
    model::Admin a = data->getAdmin(name);
    if(a.getName().compare("ERROR") != 0)
    {
        return;
    }

    // ajout de l'administrateur
    model::Admin admin(name);
    data->addAdmin(admin);

    // actualisation de la fenêtre
    window->refresh();
}

void Controller::order(QString pc, QString product, QString user)
{
    // vérifie si le pc existe
    model::PC p = data->getPC(pc);
    if(p.getName().compare("ERROR") == 0)
    {
        return;
    }

    // vérifie si l'utilisateur existe
    model::User u = data->getUser(user);
    if(u.getName().compare("ERROR") == 0)
    {
        return;
    }

    // on cherche le produit qui porte le nom rechercher
    std::vector<model::Product> prods = data->getProducts(p);
    foreach (model::Product pr, prods)
    {
        // si le nom est celui rechercher
        if(pr.getName().compare(product)==0)
        {
            // on l'ajoute
            model::Order o(p, pr, u);
            data->addOrder(o);

            // actualisation de la fenêtre
            window->refresh();
        }
    }
}
