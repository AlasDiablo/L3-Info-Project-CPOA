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
        std::string name; /**< Nom du point de collecte */
        bool check; /**< validation du point de collecte */
        std::vector<model::Productor> productors; /**< liste des producteurs du point de collecte */
        std::vector<model::Product> products; /**< liste des producteurs du point de collecte */
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
         * @brief Ajout d'un producteur au pc
         * @param producteur
         */
        void addProducteur(Productor producteur);

        /**
         * @brief Suppression d'un producteur
         * @param producteur
         */
        void removeProducteur(Productor producteur);

        /**
         * @brief Obetenir la liste des producteur
         * @return vector connenent la liste des producteur
         */
        std::vector<model::Productor> getProds();

        /**
         * @brief Ajout d'un produit au pc
         * @param produit
         */
        void addProduct(Product product);

        /**
         * @brief Suppression d'un produit
         * @param produit
         */
        void removeProduct(std::string productName, std::string prodName);

        /**
         * @brief Obetenir la liste des produit
         * @return vector connenent la liste des produit
         */
        std::vector<model::Product> getProducts();
    };
}

#endif // PC_H
