#include "admin.h"

model::Admin::Admin(std::string name)
{
    this->name = name;
}

std::string model::Admin::getName()
{
    return this->name;
}
