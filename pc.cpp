/**
 * @file pc.cpp
 * @brief PC Class
 * @author Safyrus
 * @version 1.1
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
