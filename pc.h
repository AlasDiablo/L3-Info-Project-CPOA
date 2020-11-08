#ifndef PC_H
#define PC_H

/**
 * @file pc.h
 * @brief PC Class
 * @author Safyrus
 * @version 1.1
 */

#include "user.h"

/** @namespace model
 * namespace regroupant toutes les structures de données
 */
namespace model {

    /**
     * @brief Class représentant un point de collecte
     */
    class PC
    {
    private:
        User creator; /**< Créateur du point de collecte */
        std::string name; /**< Nom du point de collecte */
    public:
        /**
         * @brief Constructeur
         */
        PC();

        /**
         * @brief Constructeur
         * @param name le nom du point de collecte
         * @param creator le createur du point de collecte
         */
        PC(std::string name, User creator);

        /**
         * @brief CHange le nom du point de collecte
         * @param name le nouveau nom
         */
        void setName(std::string name);

        /**
         * @brief Récupere le nom du point de collecte
         * @return le nom
         */
        std::string getName();

        /**
         * @brief Récupere le nom du créateur du point de collecte
         * @return le nom du créateur
         */
        std::string getCreatorName();
    };
}

#endif // PC_H
