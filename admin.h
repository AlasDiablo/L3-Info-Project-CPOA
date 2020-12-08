#ifndef ADMIN_H
#define ADMIN_H

/**
 * @file admin.h
 * @brief Admin Class
 * @author Safyrus
 * @version 1.3
 */

#include <QString>

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
        QString name; /**< Le nom de l'administrateur */
    public:
        /**
         * @brief Constructeur
         * @param name nom de l'administrateur
         */
        Admin(QString name);

        /**
         * @brief retourne le nom de l'administrateur
         * @return le nom de l'administrateur
         */
        QString getName();
    };
}

#endif // ADMIN_H
