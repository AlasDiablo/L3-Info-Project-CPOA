/**
 * @file user.cpp
 * @brief Producteur Class
 * @author AlasDiablo
 * @version 1.2
 */

#include "productor.h"

model::Productor::Productor()
{
    this->name = "";
}

model::Productor::Productor(std::string name)
{
    this->name = name;
}

std::string model::Productor::getName()
{
    return this->name;
}
