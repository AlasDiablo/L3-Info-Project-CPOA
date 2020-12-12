/**
 * @file user.cpp
 * @brief Producteur Class
 * @author AlasDiablo
 * @version 1.3
 */

#include "product.h"

model::Product::Product()
{
    this->name = "";
    this->productor = "";
    this->price = 0;
}

model::Product::Product(QString name, QString productor, float price)
{
    this->name = name;
    this->productor = productor;
    this->price = price;
}

QString model::Product::getName()
{
    return this->name;
}


QString model::Product::getProductorName()
{
    return this->productor;
}

float model::Product::getPrice()
{
    return this->price;
}
