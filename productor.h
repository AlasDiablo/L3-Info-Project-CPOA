#ifndef PRODUCTOR_H
#define PRODUCTOR_H

/**
 * @file user.h
 * @brief Producteur Class
 * @author AlasDiablo
 * @version 1.2
 */

#include <string>

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
        std::string name; /** Nom du producteur */
    public:
        /**
         * @brief Constructeur
         */
        Productor();

        /**
         * @brief Constructeur
         * @param name nom du producteur
         */
        Productor(std::string name);

        /**
         * @brief Récupere le nom du producteur
         * @return le nom
         */
        std::string getName();
    };
}

#endif // PRODUCTOR_H
