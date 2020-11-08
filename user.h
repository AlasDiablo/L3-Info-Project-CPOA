#ifndef USER_H
#define USER_H

/**
 * @file user.h
 * @brief User Class
 * @author Safyrus
 * @version 1.1
 */

#include <string>

/** @namespace model
 * namespace regroupant toutes les structures de données
 */
namespace model {

    /**
     * @brief Classe représentant un utilisateur
     */
    class User
    {
    private:
        std::string name; /**< Nom de l'utilisateur */
    public:
        /**
         * @brief Constructeur
         */
        User();

        /**
         * @brief Constructeur
         * @param name nom de l'utilisateur
         */
        User(std::string name);

        /**
         * @brief Récupere le nom de l'utilisateur
         * @return le nom
         */
        std::string getName();
    };
}

#endif // USER_H
