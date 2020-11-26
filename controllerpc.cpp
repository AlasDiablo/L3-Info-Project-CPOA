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

void ControllerPC::removeProductor(std::string name, model::Productor productor) {
    model::PC *pcPtr = data->getPC(name);
    if(pcPtr == nullptr)
    {
        return;
    } else {
        pcPtr->removeProducteur(productor);
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
