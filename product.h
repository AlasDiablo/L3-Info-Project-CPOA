#ifndef PRODUCT_H
#define PRODUCT_H

/**
 * @file user.h
 * @brief Produit Class
 * @author AlasDiablo
 * @version 1.3
 */

#include <QString>
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
        QString name; /** Nom du produit */
        QString productor;
        float price;
    public:
        Product();
        Product(QString name, QString productor, float price);

        /**
         * @brief Récupere le nom du produit
         * @return le nom
         */
        QString getName();

        QString getProductorName();

        float getPrice();
    };
}

#endif // PRODUCT_H
