/**
 * @file user.cpp
 * @brief Producteur Class
 * @author AlasDiablo
 * @version 1.3
 */

#include "product.h"

model::Product::Product(std::string name, std::string productor, float price)
{
    this->name = name;
    this->productor = productor;
    this->price = price;
}

std::string model::Product::getName()
{
    return this->name;
}


std::string model::Product::getProductorName()
{
    return this->productor;
}

float model::Product::getPrice()
{
    return this->price;
}
