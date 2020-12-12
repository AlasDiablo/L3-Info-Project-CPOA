/**
 * @file pc.cpp
 * @brief PC Class
 * @author Safyrus & AlasDiablo
 * @version 1.3
 */

#include "pc.h"

model::PC::PC()
{
    this->name = "";
    this->creator = User();
}

model::PC::PC(QString name, User creator)
{
    this->name = name;
    this->creator = creator;
}

void model::PC::setName(QString name)
{
    this->name = name;
}

QString model::PC::getName()
{
    return this->name;
}

QString model::PC::getCreatorName()
{
    return this->creator.getName();
}

void model::PC::setCheck(bool check)
{
    this->check = check;
}

bool model::PC::getCheck()
{
    return check;
}
