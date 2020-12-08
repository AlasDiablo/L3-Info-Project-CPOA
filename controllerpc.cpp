#include "controllerpc.h"
#include "mainwindow.h"

ControllerPC::ControllerPC(model::Data *data, MainWindow *window)
{
    this->data = data;
    this->window = window;
}

void ControllerPC::createPC(QString userName, QString name)
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

model::Productor ControllerPC::createProductor(QString name) {
    return model::Productor(name);
}

void ControllerPC::addProductor(QString name, QString nameProductor) {
    model::PC *pcPtr = data->getPC(name);
    if(pcPtr == nullptr)
    {
        return;
    } else {
        pcPtr->addProducteur(this->createProductor(nameProductor));
        window->refresh();
    }
}

void ControllerPC::removeProductor(QString name, QString nameProductor) {
    model::PC *pcPtr = data->getPC(name);
    if(pcPtr == nullptr)
    {
        return;
    } else {
        pcPtr->removeProducteur(this->createProductor(nameProductor));
        window->refresh();
    }
}

void ControllerPC::changePC(QString name, QString newName)
{
    model::PC *pcPtr = data->getPC(name);
    if(pcPtr == nullptr)
    {
        return;
    }
    model::PC pc = *pcPtr;
    data->removePC(name);
    model::PC newPC(newName, *data->getUser(pc.getCreatorName()));
    data->addPC(newPC);
    window->refresh();
}

void ControllerPC::deletePC(QString name)
{
    data->removePC(name);
    window->refresh();
}

void ControllerPC::addProduct(QString name, QString prodName, QString pcName)
{
    model::PC* pc = data->getPC(pcName);
    if(pc == nullptr)
    {
        return;
    }
    std::vector<model::Productor> prods = pc->getProds();
    foreach (model::Productor p, prods) {
        if(p.getName().compare(prodName)==0)
        {
            model::Product product(name, prodName, 0);
            pc->addProduct(product);
        }
    }

    window->refresh();
}

void ControllerPC::removeProduct(QString name, QString prodName, QString pcName)
{
    model::PC* pc = data->getPC(pcName);
    if(pc == nullptr)
    {
        return;
    }
    pc->removeProduct(name, prodName);

    window->refresh();
}

void ControllerPC::changeProductPrice(float price, QString name, QString prodName, QString pcName)
{
    model::PC* pc = data->getPC(pcName);
    if(pc == nullptr)
    {
        return;
    }
    std::vector<model::Product> prods = pc->getProducts();
    foreach (model::Product p, prods)
    {
        if(p.getProductorName().compare(prodName)==0 && p.getName().compare(name)==0)
        {
            pc->removeProduct(name, prodName);
            model::Product prd(name, prodName, price);
            pc->addProduct(prd);
        }
    }

    window->refresh();
}

void ControllerPC::changeProductName(QString name, QString newName, QString prodName, QString pcName)
{
    model::PC* pc = data->getPC(pcName);
    if(pc == nullptr)
    {
        return;
    }
    std::vector<model::Product> prods = pc->getProducts();
    foreach (model::Product p, prods)
    {
        if(p.getProductorName().compare(prodName)==0 && p.getName().compare(name)==0)
        {
            model::Product prd(newName, prodName, p.getPrice());
            pc->removeProduct(name, prodName);
            pc->addProduct(prd);
        }
    }

    window->refresh();
}
