#include "order.h"

model::Order::Order(model::PC pc, model::Productor productor, model::Product product, model::User user)
{
    this->pc = pc;
    this->product = product;
    this->productor = productor;
    this->user = user;
}
