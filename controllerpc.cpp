#include "controllerpc.h"
#include "mainwindow.h"

ControllerPC::ControllerPC(model::DataDB *data, MainWindow *window)
{
    this->data = data;
    this->window = window;
}

void ControllerPC::createPC(QString userName, QString name)
{
    model::User u = data->getUser(userName);
    if(u.getName().compare("ERROR") == 0)
    {
        printf("ERROR USER");
        return;
    }

    model::PC pc = data->getPC(name);
    if(pc.getName().compare("ERROR") != 0)
    {
        printf("ERROR PC");
        return;
    }

    model::PC p(name, u);
    data->addPC(p);
    window->refresh();
}

model::Productor ControllerPC::createProductor(QString name) {
    return model::Productor(name);
}

void ControllerPC::addProductor(QString name, QString nameProductor) {
    model::PC pc = data->getPC(name);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    } else {
        data->addProductor(pc, this->createProductor(nameProductor));
        window->refresh();
    }
}

void ControllerPC::removeProductor(QString name, QString nameProductor) {
    model::PC pc = data->getPC(name);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    } else {
        data->removeProductor(pc, (this->createProductor(nameProductor)));
        window->refresh();
    }
}

void ControllerPC::changePC(QString name, QString newName)
{
    model::PC pc = data->getPC(name);
    pc.setName(newName);
    data->changePC(name, pc);
    window->refresh();
}

void ControllerPC::deletePC(QString name)
{
    data->removePC(name);
    window->refresh();
}

void ControllerPC::addProduct(QString name, QString prodName, QString pcName)
{
    model::PC pc = data->getPC(pcName);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    }
    std::vector<model::Productor> prods = data->getProductors(pc);
    foreach (model::Productor p, prods) {
        if(p.getName().compare(prodName)==0)
        {
            model::Product product(name, prodName, 0);
            data->addProduct(pc, product);
        }
    }

    window->refresh();
}

void ControllerPC::removeProduct(QString name, QString prodName, QString pcName)
{
    model::PC pc = data->getPC(pcName);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    }
    std::vector<model::Productor> prods = data->getProductors(pc);
    foreach (model::Productor prod, prods) {
        if(prod.getName().compare(prodName) == 0) {
            std::vector<model::Product> products = data->getProducts(pc, prod);
            foreach (model::Product product, products) {
                if(product.getName().compare(name) == 0) {
                    data->removeProduct(pc, product);
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
    std::vector<model::Product> prods = data->getProducts(pc, prod);
    foreach (model::Product p, prods)
    {
        if(p.getName().compare(name)==0)
        {
            model::Product prd(name, prodName, price);
            data->changeProduct(pc, p, prd);
            window->refresh();
        }
    }
}

void ControllerPC::changeProductName(QString name, QString newName, QString prodName, QString pcName)
{
    model::PC pc = data->getPC(pcName);
    if(pc.getName().compare("ERROR") == 0)
    {
        return;
    }
    std::vector<model::Product> prods = data->getProducts(pc);
    foreach (model::Product p, prods)
    {
        if(p.getProductorName().compare(prodName)==0 && p.getName().compare(name)==0)
        {
            model::Product prd(newName, prodName, p.getPrice());
            data->changeProduct(pc, p, prd);
            window->refresh();
        }
    }

    window->refresh();
}

void ControllerPC::checkPC(QString pc, QString admin)
{
    model::Admin a = data->getAdmin(admin);
    if(a.getName().compare("ERROR") == 0)
    {
        return;
    }

    model::PC p = data->getPC(pc);
    p.setCheck(!p.getCheck());
    data->changePC(p.getName(), p);
    window->refresh();
}

void ControllerPC::openPC(QString pc, QString user)
{
    model::PC p = data->getPC(pc);
    if(p.getName().compare("ERROR") == 0)
    {
        return;
    }
    model::User u = data->getUser(user);
    if(u.getName().compare(p.getCreatorName()) != 0)
    {
        return;
    }
    p.setOpen(!p.getOpen());
    data->changePC(pc, p);
    window->refresh();
}
