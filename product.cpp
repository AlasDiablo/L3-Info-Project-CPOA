/**
 * @file user.cpp
 * @brief Producteur Class
 * @author AlasDiablo
 * @version 1.3
 */

#include "product.h"

model::Product::Product(std::string name, model::Productor *productor, int price)
{
    this->name = name;
    this->productor = productor;
    this->price = price;
}

std::string model::Product::getName()
{
    return this->name;
}


model::Productor* model::Product::getProductor()
{
    return this->productor;
}

int model::Product::getPrice()
{
    return this->price;
}
