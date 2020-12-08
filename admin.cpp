#include "admin.h"

model::Admin::Admin(QString name)
{
    this->name = name;
}

QString model::Admin::getName()
{
    return this->name;
}
