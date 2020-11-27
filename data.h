#ifndef DATA_H
#define DATA_H

/**
 * @file data.h
 * @brief Data Class
 * @author Safyrus
 * @version 1.2
 */

#include "user.h"
#include "pc.h"
#include "admin.h"

#include <vector>

/** @namespace model
 * namespace regroupant toutes les structures de données
 */
namespace model {

    /**
     * @brief Classe utilisé pour acceder a toutes les données
     */
    class Data
    {
    private:
        std::vector<model::User> users; /**< Liste des utilisateurs */
        std::vector<model::PC> pcs; /**< Liste des points de collecte */
        std::vector<model::Admin> admins; /**< Liste des Administrateurs */
    public:
        /**
         * @brief Constructeur
         */
        Data();

        /**
         * @brief récupere le nombre d'utilisateur
         * @return le nombre d'utilisateur
         */
        unsigned int getUserSize();

        /**
         * @brief récupere l'utilisateur à l'index i
         * @param i l'index
         * @return l'utilisateur
         */
        model::User* getUser(int i);

        /**
         * @brief récupere l'utilisateur avec le nom name
         * @param name le nom
         * @return l'utilisateur
         */
        model::User* getUser(std::string name);

        /**
         * @brief récupere une liste des utilisateurs
         * @return une liste des utilisateurs
         */
        std::vector<model::User> getUser();

        /**
         * @brief récupere le nombre de point de collecte
         * @return le nombre de point de collecte
         */
        unsigned int getPCSize();

        /**
         * @brief récupere le point de collecte à l'index i
         * @param i l'index
         * @return le point de collecte
         */
        model::PC* getPC(int i);

        /**
         * @brief récupere le point de collecte avec le nom name
         * @param name le nom
         * @return le point de collecte
         */
        model::PC* getPC(std::string name);

        /**
         * @brief récupere une liste des points de collecte
         * @return une liste des points de collecte
         */
        std::vector<model::PC> getPC();

        /**
         * @brief ajoute un utilisateur
         * @param u l'utilisateur
         */
        void addUser(User u);

        /**
         * @brief ajoute un point de collecte
         * @param p le point de collecte
         */
        void addPC(PC p);

        /**
         * @brief retire l'utilisateur avec le nom name
         * @param name le nom
         */
        void removeUser(std::string name);

        /**
         * @brief retire le point de collecte avec le nom name
         * @param name le nom
         */
        void removePC(std::string name);

        /**
         * @brief retire l'utilisateur a l'index i
         * @param i l'index
         */
        void removeUser(int i);

        /**
         * @brief retire le point de collecte avec le nom name
         * @param i l'index
         */
        void removePC(int i);

        /**
         * @brief ajoute un administrateur
         * @param a l'administrateur à ajouter
         */
        void addAdmin(model::Admin a);

        /**
         * @brief supprime un administrateur
         * @param name le nom de l'administrateur à supprimer
         */
        void removeAdmin(std::string name);

        /**
         * @brief supprime un administrateur
         * @param i l'index
         */
        void removeAdmin(int i);

        /**
         * @brief récupere un administrateur
         * @param i l'index
         * @return l'administrateur
         */
        model::Admin* getAdmin(int i);

        /**
         * @brief récupere un administrateur
         * @param name le nom de l'administrateur
         * @return l'administrateur
         */
        model::Admin* getAdmin(std::string name);

        /**
         * @brief retourne la liste des administrateurs
         * @return la liste des administrateurs
         */
        std::vector<model::Admin> getAdmin();
    };
}

#endif // DATA_H
