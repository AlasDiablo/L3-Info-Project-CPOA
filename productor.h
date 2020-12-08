#ifndef PRODUCTOR_H
#define PRODUCTOR_H

/**
 * @file user.h
 * @brief Producteur Class
 * @author AlasDiablo
 * @version 1.3
 */

#include <QString>

/** @namespace model
 * namespace regroupant toutes les structures de données
 */
namespace model {

    /**
     * @brief Classe représentant un producteur
     */
    class Productor
    {
    private:
        QString name; /** Nom du producteur */
    public:
        /**
         * @brief Constructeur
         */
        Productor();

        /**
         * @brief Constructeur
         * @param name nom du producteur
         */
        Productor(QString name);

        /**
         * @brief Récupere le nom du producteur
         * @return le nom
         */
        QString getName();
    };
}

#endif // PRODUCTOR_H
