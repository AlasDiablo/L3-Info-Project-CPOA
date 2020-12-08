#ifndef PRODUCT_H
#define PRODUCT_H

/**
 * @file user.h
 * @brief Produit Class
 * @author AlasDiablo
 * @version 1.3
 */

#include <string>
#include "productor.h"

/** @namespace model
 * namespace regroupant toutes les structures de données
 */
namespace model {

    /**
     * @brief Classe représentant un produit
     */
    class Product
    {
    private:
        std::string name; /** Nom du produit */
        std::string productor;
        int price;
    public:
        Product(std::string name, std::string productor, int price);

        /**
         * @brief Récupere le nom du produit
         * @return le nom
         */
        std::string getName();

        std::string getProductorName();

        int getPrice();
    };
}

#endif // PRODUCT_H
