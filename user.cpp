/**
 * @file user.cpp
 * @brief User Class
 * @author Safyrus
 * @version 1.1
 */

#include "user.h"

model::User::User()
{
    this->name = "";
}

model::User::User(std::string name)
{
    this->name = name;
}

std::string model::User::getName()
{
    return this->name;
}
