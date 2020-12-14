#ifndef ORDER_H
#define ORDER_H

/**
 * @file order.h
 * @brief Order Class
 * @author Safyrus & AlasDiablo
 * @version 1.7
 */

#include "pc.h"
#include "product.h"
#include "productor.h"

/** @namespace model
 * namespace regroupant toutes les structures de données
 */
namespace model {

    /**
     * @brief Class representant une commande
     */
    class Order
    {
    private:
        model::PC pc; /**< Point de collecte */
        model::Product product; /**< Le produit commander */
        model::User user; /**< L'utilisateur qui a commander */

    public:
        /**
         * @brief Constructeur
         * @param pc point de collecte
         * @param product produit
         * @param user utilisateur
         */
        Order(model::PC pc, model::Product product, model::User user);

        /**
         * @brief Récupere le produit
         * @return le produit
         */
        model::Product getProduct();

        /**
         * @brief Récupere le point de collecte
         * @return le point de collecte
         */
        model::PC getPC();

        /**
         * @brief Récupere l'utilisateur
         * @return l'utilisateur
         */
        model::User getUser();
    };
}

#endif // ORDER_H
