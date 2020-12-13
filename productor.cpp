/**
 * @file user.cpp
 * @brief Producteur Class
 * @author AlasDiablo
 * @version 1.3
 */

#include "productor.h"

model::Productor::Productor()
{
    this->name = "";
}

model::Productor::Productor(QString name)
{
    this->name = name;
}

QString model::Productor::getName()
{
    return this->name;
}
