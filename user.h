#ifndef USER_H
#define USER_H

/**
 * @file user.h
 * @brief User Class
 * @author Safyrus
 * @version 1.3
 */

#include <QString>

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
        QString name; /**< Nom de l'utilisateur */
    public:
        /**
         * @brief Constructeur
         */
        User();

        /**
         * @brief Constructeur
         * @param name nom de l'utilisateur
         */
        User(QString name);

        /**
         * @brief Récupere le nom de l'utilisateur
         * @return le nom
         */
        QString getName();
    };
}

#endif // USER_H
