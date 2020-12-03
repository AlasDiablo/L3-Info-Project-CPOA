/**
 * @file pc.cpp
 * @brief PC Class
 * @author Safyrus & AlasDiablo
 * @version 1.2
 */

#include "pc.h"

model::PC::PC()
{
    this->name = "";
    this->creator = User();
}

model::PC::PC(std::string name, User creator)
{
    this->name = name;
    this->creator = creator;
}

void model::PC::setName(std::string name)
{
    this->name = name;
}

std::string model::PC::getName()
{
    return this->name;
}

std::string model::PC::getCreatorName()
{
    return this->creator.getName();
}

void model::PC::addProducteur(Productor producteur)
{
    productors.push_back(producteur);
}

void model::PC::removeProducteur(Productor producteur) {
    for(unsigned int i=0; i< productors.size(); i++) {
        model::Productor *tmp = &productors.at(i);
        if(tmp->getName().compare(producteur.getName())==0)
        {
            productors.erase(productors.begin()+i);
            break;
        }
    }
}


void model::PC::addProduct(Product product)
{
    products.push_back(product);
}

void model::PC::removeProduct(Product product)
{
    for(unsigned int i=0; i< products.size(); i++) {

        model::Product *tmp = &products.at(i);

        if (
                (tmp->getName().compare(product.getName()) == 0) &&
                (tmp->getProductor()->getName().compare(product.getProductor()->getName()) == 0)
        ) {
            products.erase(products.begin()+i);
            break;
        }

    }
}

void model::PC::setCheck(bool check)
{
    this->check = check;
}

bool model::PC::getCheck()
{
    return check;
}

std::vector<model::Productor> model::PC::getProds()
{
    return productors;
}

std::vector<model::Product> model::PC::getProducts()
{
    return products;
}
