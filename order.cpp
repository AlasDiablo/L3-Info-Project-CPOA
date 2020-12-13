#include "order.h"

model::Order::Order(model::PC pc, model::Product product, model::User user)
{
    this->pc = pc;
    this->product = product;
    this->user = user;
}


bool model::Order::getDelivery()
{
    return this->delivery;
}

void model::Order::setDelivery(bool delivery)
{
    this->delivery = delivery;
}

model::PC model::Order::getPC()
{
    return this->pc;
}

model::User model::Order::getUser()
{
    return this->user;
}

model::Product model::Order::getProduct()
{
    return this->product;
}
