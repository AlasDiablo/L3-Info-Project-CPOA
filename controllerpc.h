#ifndef CONTROLLERPC_H
#define CONTROLLERPC_H

/**
 * @file controllerpc.h
 * @brief Controller PC Class
 * @author Safyrus & AlasDiablo
 * @version 1.2
 */

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

    /**
     * @brief deletePC
     * @param name
     */
    void deletePC(std::string name);

    /**
     * @brief Créer un nouveau producteur
     * @param name le nom du producteur
     */
    model::Productor createProductor(std::string name);

    /**
     * @brief Ajout d'un producteur
     * @param name nom du pc
     * @param productor producteur
     */
    void addProductor(std::string name, model::Productor productor);

    /**
     * @brief Supprestion d'un producteur
     * @param name nom du pc
     * @param productor producteur
     */
    void removeProductor(std::string name, model::Productor productor);
};

#endif // CONTROLLERPC_H
