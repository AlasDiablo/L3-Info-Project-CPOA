#ifndef ADMIN_H
#define ADMIN_H

/**
 * @file admin.h
 * @brief Admin Class
 * @author Safyrus
 * @version 1.2
 */

#include <string>

/** @namespace model
 * namespace regroupant toutes les structures de données
 */
namespace model {
    /**
     * @brief Class representant un administrateur
     */
    class Admin
    {
    private:
        std::string name; /**< Le nom de l'administrateur */
    public:
        /**
         * @brief Constructeur
         * @param name nom de l'administrateur
         */
        Admin(std::string name);

        /**
         * @brief retourne le nom de l'administrateur
         * @return le nom de l'administrateur
         */
        std::string getName();
    };
}

#endif // ADMIN_H
