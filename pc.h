#ifndef PC_H
#define PC_H

/**
 * @file pc.h
 * @brief PC Class
 * @author Safyrus & AlasDiablo
 * @version 1.3
 */

#include "user.h"
#include "admin.h"
#include "productor.h"
#include "product.h"
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
        QString name; /**< Nom du point de collecte */
        bool check; /**< validation du point de collecte */
        bool open; /**< ouverture du point de collecte */
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
        PC(QString name, User creator);

        /**
         * @brief CHange le nom du point de collecte
         * @param name le nouveau nom
         */
        void setName(QString name);

        /**
         * @brief Récupere le nom du point de collecte
         * @return le nom
         */
        QString getName();

        /**
         * @brief Récupere le nom du créateur du point de collecte
         * @return le nom du créateur
         */
        QString getCreatorName();

        /**
         * @brief modifie la validation du PC
         * @param check validation
         */
        void setCheck(bool check);

        /**
         * @brief retourne si le PC est validé
         * @return la validation
         */
        bool getCheck();

        /**
         * @brief modifie l'ouverture du PC
         * @param open ouverture
         */
        void setOpen(bool open);

        /**
         * @brief retourne si le PC est ouvert
         * @return l'ourverture
         */
        bool getOpen();
    };
}

#endif // PC_H
