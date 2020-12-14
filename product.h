#ifndef PRODUCT_H
#define PRODUCT_H

/**
 * @file user.h
 * @brief Produit Class
 * @author AlasDiablo
 * @version 1.7
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
        QString name; /**< Nom du produit */
        QString productor; /**< Nom du producteur */
        float price; /**< Prix */
    public:
        /**
         * @brief Constructeur
         */
        Product();

        /**
         * @brief Constructeur
         * @param name nom du produit
         * @param productor nom du producteur
         * @param price prix du produit
         */
        Product(QString name, QString productor, float price);

        /**
         * @brief Récupere le nom du produit
         * @return le nom du produit
         */
        QString getName();

        /**
         * @brief Récupere le nom du producteur
         * @return le nom du producteur
         */
        QString getProductorName();

        /**
         * @brief Récupere le prix du produit
         * @return le prix
         */
        float getPrice();
    };
}

#endif // PRODUCT_H
