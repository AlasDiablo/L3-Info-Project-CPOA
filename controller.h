#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
 * @file controller.h
 * @brief Controller Class
 * @author Safyrus
 * @version 1.1
 */

#include "data.h"

#include <string>

class MainWindow;

/**
 * @brief Classe permettant de controller les données
 */
class Controller
{
private:
    model::Data *data; /**< Les données a controller */
    MainWindow *window; /**< La fenetre a actualiser */
public:
    /**
     * @brief Constructeur
     * @param data Les données a controller
     * @param window La fenetre a actualiser
     */
    Controller(model::Data *data, MainWindow *window);

    /**
     * @brief Créer un nouveau point de collecte
     * @param userName le nom du créateur
     * @param name le nom du point de collecte
     */
    void createPC(std::string userName, std::string name);

    /**
     * @brief Créer un nouveau utilisateur
     * @param name le nom de l'tuilisateur
     */
    void createUser(std::string name);

    /**
     * @brief Modifie un utilisateur
     * @param name le nom de l'utilisateur
     * @param newName le nouveau nom de l'utilisateur
     */
    void changeUser(std::string name, std::string newName);

    /**
     * @brief Modifie un point de collecte
     * @param name le nom du point de collecte
     * @param newName le nouveau nom du point de collecte
     */
    void changePC(std::string name, std::string newName);
};

#endif // CONTROLLER_H
