#ifndef CONTROLLERPC_H
#define CONTROLLERPC_H

/**
 * @file controllerpc.h
 * @brief Controller PC Class
 * @author Safyrus & AlasDiablo
 * @version 1.7
 */

#include "datadb.h"

class MainWindow;

/**
 * @brief Class permettant de réaliser les actions relier aux PC
 */
class ControllerPC
{
private:
    model::DataDB *data; /**< Les données a controller */
    MainWindow *window; /**< La fenetre a actualiser */

    /**
     * @brief Créer un nouveau producteur
     * @param name le nom du producteur
     */
    model::Productor createProductor(QString name);
public:
    /**
     * @brief Constructeur
     * @param data Les données a controller
     * @param window La fenetre a actualiser
     */
    ControllerPC(model::DataDB *data, MainWindow *window);

    /**
     * @brief Créer un nouveau point de collecte
     * @param userName le nom du créateur
     * @param name le nom du point de collecte
     */
    void createPC(QString userName, QString name);

    /**
     * @brief Modifie un point de collecte
     * @param name le nom du point de collecte
     * @param newName le nouveau nom du point de collecte
     */
    void changePC(QString name, QString newName);

    /**
     * @brief deletePC
     * @param name
     */
    void deletePC(QString name);

    /**
     * @brief Ajout d'un producteur
     * @param name nom du pc
     * @param productor producteur
     */
    void addProductor(QString name, QString nameProductor);

    /**
     * @brief Suppression d'un producteur
     * @param name nom du pc
     * @param productor producteur
     */
    void removeProductor(QString name, QString nameProductor);

    /**
     * @brief Ajoute un produit associe a un producteur
     * @param name nom du produit
     * @param prodName nom du producteur
     * @param pcName nom du pc
     */
    void addProduct(QString name, QString prodName, QString pcName);

    /**
     * @brief Supprime un produit associe a un producteur
     * @param name nom du produit
     * @param productorName nom du producteur
     */
    void removeProduct(QString name, QString productorName, QString pcName);

    /**
     * @brief Change le prix du produit
     * @param price nouveau prix
     * @param name nom du produit
     * @param productorName nom du producteur
     */
    void changeProductPrice(float price, QString name, QString productorName, QString pcName);

    /**
     * @brief Change le nom du produit
     * @param name nom du produit
     * @param newName nouveau nom du produit
     * @param productorName nom du producteur
     */
    void changeProductName(QString name, QString newName, QString productorName, QString pcName);

    /**
     * @brief valide ou invalide on point de collecte
     * @param pc le point de collecte
     * @param admin l'administrateur
     */
    void checkPC(QString pc, QString admin);

    /**
     * @brief Ouvre ou ferme un point de collecte
     * @param pc le nom du point de collecte
     * @param user le nom de l'utilisateur
     */
    void openPC(QString pc, QString user);
};

#endif // CONTROLLERPC_H
