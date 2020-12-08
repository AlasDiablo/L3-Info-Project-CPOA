/**
 * @file user.cpp
 * @brief User Class
 * @author Safyrus
 * @version 1.3
 */

#include "user.h"

model::User::User()
{
    this->name = "";
}

model::User::User(QString name)
{
    this->name = name;
}

QString model::User::getName()
{
    return this->name;
}
