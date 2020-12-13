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
        model::Product product;
        model::User user;

    public:
        Order(model::PC pc, model::Product product, model::User user);
        model::Product getProduct();
        model::PC getPC();
        model::User getUser();
    };
}

#endif // ORDER_H
