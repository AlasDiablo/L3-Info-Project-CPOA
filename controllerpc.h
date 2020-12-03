#ifndef CONTROLLERPC_H
#define CONTROLLERPC_H

/**
 * @file controllerpc.h
 * @brief Controller PC Class
 * @author Safyrus & AlasDiablo
 * @version 1.3
 */

#include "data.h"

class MainWindow;

/**
 * @brief Class permettant de réaliser les actions relier aux PC
 */
class ControllerPC
{
private:
    model::Data *data; /**< Les données a controller */
    MainWindow *window; /**< La fenetre a actualiser */

    /**
     * @brief Créer un nouveau producteur
     * @param name le nom du producteur
     */
    model::Productor createProductor(std::string name);
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
     * @brief Ajout d'un producteur
     * @param name nom du pc
     * @param productor producteur
     */
    void addProductor(std::string name, std::string nameProductor);

    /**
     * @brief Suppression d'un producteur
     * @param name nom du pc
     * @param productor producteur
     */
    void removeProductor(std::string name, model::Productor productor);

    /**
     * @brief Ajoute un produit associe a un producteur
     * @param name nom du produit
     * @param prodName nom du producteur
     * @param pcName nom du pc
     */
    void addProduct(std::string name, std::string prodName, std::string pcName);

    /**
     * @brief Supprime un produit associe a un producteur
     * @param name nom du produit
     * @param productorName nom du producteur
     */
    void removeProduct(std::string name, std::string productorName);

    /**
     * @brief Change le prix du produit
     * @param price nouveau prix
     * @param name nom du produit
     * @param productorName nom du producteur
     */
    void changeProductPrice(float price, std::string name, std::string productorName);

    /**
     * @brief Change le nom du produit
     * @param name nom du produit
     * @param newName nouveau nom du produit
     * @param productorName nom du producteur
     */
    void changeProductName(std::string name, std::string newName, std::string productorName);
};

#endif // CONTROLLERPC_H
