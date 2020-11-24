#ifndef CONTROLLERPC_H
#define CONTROLLERPC_H

#include "data.h"

class MainWindow;

class ControllerPC
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
    ControllerPC(model::Data *data, MainWindow *window);

    /**
     * @brief Créer un nouveau point de collecte
     * @param userName le nom du créateur
     * @param name le nom du point de collecte
     */
    void createPC(std::string userName, std::string name);

    /**
     * @brief Modifie un point de collecte
     * @param name le nom du point de collecte
     * @param newName le nouveau nom du point de collecte
     */
    void changePC(std::string name, std::string newName);

    void deletePC(std::string name);
};

#endif // CONTROLLERPC_H
