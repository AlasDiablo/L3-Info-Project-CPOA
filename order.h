#ifndef ORDER_H
#define ORDER_H

#include "pc.h"
#include "product.h"
#include "productor.h"

namespace model {
    class Order
    {
    private:
        model::PC pc;
        model::Productor productor;
        model::Product product;
        model::User user;

    public:
        Order(model::PC pc, model::Productor productor, model::Product product, model::User user);
    };
}

#endif // ORDER_H
