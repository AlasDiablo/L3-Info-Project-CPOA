/**
 * @file controllerpc.cpp
 * @brief ControllerPC Class
 * @author Safyrus
 * @version 1.7
 */

#include "controllerpc.h"
#include "mainwindow.h"

ControllerPC::ControllerPC(model::DataDB *data, MainWindow *window)
{
    this->data = data;
    this->window = window;
}

void ControllerPC::createPC(QString userName, QString name)
{
    // vérifie si l'utilisateur existe
    model::User u = data->getUser(userName);
    if(u.getName().compare("ERROR") == 0)
    {
        return;
    }

    // vérifie si le pc n'existe pas déjà
    model::PC pc = data->getPC(name);
    if(pc.getName().compare("ERROR") != 0)
    {
        return;
    }

    // ajout du pc
    model::PC p(name, u);
    data->addPC(p);

    // actualisation de la fenêtre
    window->refresh();
}

model::Productor ControllerPC::createProductor(QString name) {
    return model::Productor(name);
}

void ControllerPC::addProductor(QString name, QString nameProductor) {
    // vérifie si le pc existe
    model::PC pc = data->getPC(name);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    }

    // ajout du producteur
    data->addProductor(pc, this->createProductor(nameProductor));

    // actualisation de la fenêtre
    window->refresh();
}

void ControllerPC::removeProductor(QString name, QString nameProductor) {
    // vérifie si le pc existe
    model::PC pc = data->getPC(name);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    }

    // suppression du producteur
    data->removeProductor(pc, (this->createProductor(nameProductor)));

    // actualisation de la fenêtre
    window->refresh();
}

void ControllerPC::changePC(QString name, QString newName)
{
    // modification du pc
    model::PC pc = data->getPC(name);
    pc.setName(newName);
    data->changePC(name, pc);

    // actualisation de la fenêtre
    window->refresh();
}

void ControllerPC::deletePC(QString name)
{
    // suppression du pc
    data->removePC(name);

    // actualisation de la fenêtre
    window->refresh();
}

void ControllerPC::addProduct(QString name, QString prodName, QString pcName)
{
    // vérifie si le pc existe
    model::PC pc = data->getPC(pcName);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    }

    // cherche le producteur avec le nom prodName
    std::vector<model::Productor> prods = data->getProductors(pc);
    foreach (model::Productor p, prods) {
        if(p.getName().compare(prodName)==0)
        {
            // ajout du produit
            model::Product product(name, prodName, 0);
            data->addProduct(pc, product);
        }
    }

    // actualisation de la fenêtre
    window->refresh();
}

void ControllerPC::removeProduct(QString name, QString prodName, QString pcName)
{
    // vérifie si le pc existe
    model::PC pc = data->getPC(pcName);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    }

    // cherche parmis les producteurs
    std::vector<model::Productor> prods = data->getProductors(pc);
    foreach (model::Productor prod, prods) {
        if(prod.getName().compare(prodName) == 0) {
            // cherche parmis les produits
            std::vector<model::Product> products = data->getProducts(pc, prod);
            foreach (model::Product product, products) {
                if(product.getName().compare(name) == 0) {
                    // suppression du produit
                    data->removeProduct(pc, product);

                    // actualisation de la fenêtre
                    window->refresh();
                }
            }
        }
    }
}

void ControllerPC::changeProductPrice(float price, QString name, QString prodName, QString pcName)
{
    model::User u;
    model::PC pc(pcName, u);
    model::Productor prod(prodName);

    // cherche parmis les produits
    std::vector<model::Product> prods = data->getProducts(pc, prod);
    foreach (model::Product p, prods)
    {
        if(p.getName().compare(name)==0)
        {
            // modification du produit
            model::Product prd(name, prodName, price);
            data->changeProduct(pc, p, prd);

            // actualisation de la fenêtre
            window->refresh();
        }
    }
}

void ControllerPC::changeProductName(QString name, QString newName, QString prodName, QString pcName)
{
    // vérifie si le pc existe
    model::PC pc = data->getPC(pcName);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    }

    // cherche parmis les produits
    std::vector<model::Product> prods = data->getProducts(pc);
    foreach (model::Product p, prods)
    {
        if(p.getProductorName().compare(prodName)==0 && p.getName().compare(name)==0)
        {
            // modification du produit
            model::Product prd(newName, prodName, p.getPrice());
            data->changeProduct(pc, p, prd);

            // actualisation de la fenêtre
            window->refresh();
        }
    }
}

void ControllerPC::checkPC(QString pc, QString admin)
{
    // vérifie si l'administrateur existe
    model::Admin a = data->getAdmin(admin);
    if(a.getName().compare("ERROR") == 0)
    {
        return;
    }

    // modification du pc
    model::PC p = data->getPC(pc);
    p.setCheck(!p.getCheck());
    data->changePC(p.getName(), p);

    // actualisation de la fenêtre
    window->refresh();
}

void ControllerPC::openPC(QString pc, QString user)
{
    // vérifie si le pc existe
    model::PC p = data->getPC(pc);
    if(p.getName().compare("ERROR") == 0)
    {
        return;
    }

    // vérifie si le nom correspond a celui du propriétaire du pc
    model::User u = data->getUser(user);
    if(u.getName().compare(p.getCreatorName()) != 0)
    {
        return;
    }

    // changement du pc
    p.setOpen(!p.getOpen());
    data->changePC(pc, p);

    // actualisation de la fenêtre
    window->refresh();
}
