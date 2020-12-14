/**
 * @file admin.cpp
 * @brief Admin Class
 */
#include "admin.h"

model::Admin::Admin(QString name)
{
    this->name = name;
}

QString model::Admin::getName()
{
    return this->name;
}
