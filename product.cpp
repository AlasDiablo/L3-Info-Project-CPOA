/**
 * @file user.cpp
 * @brief Producteur Class
 * @author AlasDiablo
 * @version 1.3
 */

#include "product.h"

model::Product::Product(std::string name, model::Productor *productor)
{
    this->name = name;
    this->productor = productor;
}

std::string model::Product::getName()
{
    return this->name;
}


model::Productor* model::Product::getProductor()
{
    return this->productor;
}
