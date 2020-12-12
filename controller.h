#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
 * @file controller.h
 * @brief Controller Class
 * @author Safyrus
 * @version 1.3
 */

#include "datadb.h"

#include <string>

class MainWindow;

/**
 * @brief Classe permettant de controller les données
 */
class Controller
{
private:
    model::DataDB *data; /**< Les données a controller */
    MainWindow *window; /**< La fenetre a actualiser */
public:
    /**
     * @brief Constructeur
     * @param data Les données a controller
     * @param window La fenetre a actualiser
     */
    Controller(model::DataDB *data, MainWindow *window);

    /**
     * @brief Créer un nouveau utilisateur
     * @param name le nom de l'tuilisateur
     */
    void createUser(QString name);

    /**
     * @brief Modifie un utilisateur
     * @param name le nom de l'utilisateur
     * @param newName le nouveau nom de l'utilisateur
     */
    void changeUser(QString name, QString newName);

    void deleteUser(QString name);

    /**
     * @brief Créer un nouveau administrateur
     * @param name nom de l'administrateur
     */
    void createAdmin(QString name);

    void order(QString product, QString user);

    void deliver(QString product);

    void checkDelivery(QString delivery);
};

#endif // CONTROLLER_H
