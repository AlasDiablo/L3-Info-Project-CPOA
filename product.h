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
        model::Productor* productor;
        int price;
    public:
        /**
         * @brief Constructeur
         * @param name nom du produit
         * @param productor pointeur vers le producteur
         */
        Product(std::string name, model::Productor *productor, int price);

        /**
         * @brief Récupere le nom du produit
         * @return le nom
         */
        std::string getName();

        /**
         * @brief Récupere le producteur du produit
         * @return un pointeur vers le producteur
         */
        model::Productor* getProductor();

        int getPrice();
    };
}

#endif // PRODUCT_H
