#ifndef PC_H
#define PC_H

/**
 * @file pc.h
 * @brief PC Class
 * @author Safyrus & AlasDiablo
 * @version 1.2
 */

#include "user.h"
#include "admin.h"
#include "productor.h"
#include <vector>

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
        bool check;
        std::vector<model::Productor> productors;
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

        /**
         * @brief
         * @param check
         */
        void setCheck(bool check);

        /**
         * @brief
         * @return
         */
        bool getCheck();

        /**
         * @brief Ajout d'un producteur au pc
         * @param producteur
         */
        void addProducteur(Productor producteur);

        /**
         * @brief Supprestion d'un producteur
         * @param producteur
         */
        void removeProducteur(Productor producteur);
    };
}

#endif // PC_H
