#include "controllerpc.h"
#include "mainwindow.h"

ControllerPC::ControllerPC(model::Data *data, MainWindow *window)
{
    this->data = data;
    this->window = window;
}

void ControllerPC::createPC(std::string userName, std::string name)
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

model::Productor ControllerPC::createProductor(std::string name) {
    return model::Productor(name);
}

void ControllerPC::addProductor(std::string name, std::string nameProductor) {
    model::PC *pcPtr = data->getPC(name);
    if(pcPtr == nullptr)
    {
        return;
    } else {
        pcPtr->addProducteur(this->createProductor(nameProductor));
        window->refresh();
    }
}

void ControllerPC::removeProductor(std::string name, std::string nameProductor) {
    model::PC *pcPtr = data->getPC(name);
    if(pcPtr == nullptr)
    {
        return;
    } else {
        pcPtr->removeProducteur(this->createProductor(nameProductor));
        window->refresh();
    }
}

void ControllerPC::changePC(std::string name, std::string newName)
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

void ControllerPC::deletePC(std::string name)
{
    data->removePC(name);
    window->refresh();
}

void ControllerPC::addProduct(std::string name, std::string prodName, std::string pcName)
{
    model::PC* pc = data->getPC(pcName);
    std::vector<model::Productor> prods = pc->getProds();
    foreach (model::Productor p, prods) {
        if(p.getName().compare(prodName)==0)
        {
            model::Productor *prod = &p;
            model::Product product(name, prod, 0);
            pc->addProduct(product);
        }
    }

    window->refresh();
}

void ControllerPC::removeProduct(std::string name, std::string prodName, std::string pcName)
{
    model::PC* pc = data->getPC(pcName);
    std::vector<model::Productor> prods = pc->getProds();
    std::vector<model::Product> products = pc->getProducts();

    foreach (model::Productor p, prods) {
        if(p.getName().compare(prodName)==0)
        {
            model::Productor *prod = &p;
            model::Product product(name, prod, 0);
            pc->removeProduct(product);
        }
    }

    window->refresh();
}

void ControllerPC::changeProductPrice(float price, std::string name, std::string prodName, std::string pcName)
{
    model::PC* pc = data->getPC(pcName);
    std::vector<model::Productor> prods = pc->getProds();
    std::vector<model::Product> products = pc->getProducts();

    foreach (model::Productor p, prods) {
        if(p.getName().compare(prodName)==0)
        {
            model::Productor *prod = &p;
            model::Product product(name, prod, price);
            for(unsigned int i=0; i< products.size(); i++) {
                model::Product *tmp = &products.at(i);
                if (
                        (tmp->getName().compare(product.getName()) == 0) &&
                        (tmp->getProductor()->getName().compare(product.getProductor()->getName()) == 0)
                ) {
                    pc->removeProduct(product);
                    pc->addProduct(product);
                }
            }
        }
    }
}

void ControllerPC::changeProductName(std::string name, std::string newName, std::string prodName, std::string pcName)
{
    model::PC* pc = data->getPC(pcName);
    std::vector<model::Productor> prods = pc->getProds();
    std::vector<model::Product> products = pc->getProducts();

    foreach (model::Productor p, prods) {
        if(p.getName().compare(prodName)==0)
        {
            model::Productor *prod = &p;
            model::Product product(name, prod, 0);

            for(unsigned int i=0; i< products.size(); i++) {
                model::Product *tmp = &products.at(i);
                if (
                        (tmp->getName().compare(product.getName()) == 0) &&
                        (tmp->getProductor()->getName().compare(product.getProductor()->getName()) == 0)
                ) {
                    model::Product newProduct(newName, prod, tmp->getPrice());
                    pc->removeProduct(product);
                    pc->addProduct(newProduct);
                }
            }
        }
    }
}
