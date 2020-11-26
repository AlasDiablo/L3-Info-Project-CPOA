#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @file mainwindow.h
 * @brief MainWindow Class
 * @author Safyrus
 * @version 1.2
 */

#include "user.h"
#include "pc.h"
#include "data.h"
#include "controller.h"
#include "controllerpc.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

/**
 * @brief Class représentant la fenetre principale
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton *b_CreatePC; /**< Bouton pour créer un point de collecte */
    QPushButton *b_CreateUser; /**< Bouton pour créer un utilisateur */
    QPushButton *b_ChangeUser; /**< Bouton pour changer un utilisateur */
    QPushButton *b_ChangePC; /**< Bouton pour changer un point de collecte */
    QPushButton *b_DeletePC; /**< Bouton pour supprimer un point de collecte */
    QPushButton *b_CreateAdmin; /**< Bouton pour créer un Admin */
    QPushButton *b_CheckPC; /**< Bouton pour valider un PC */
    QPushButton *b_AddProdPC; /**< Bouton pour ajouter un Producteur a un  PC */
    QPushButton *b_RemoveProdPC; /**< Bouton pour retirer un Producteur d'un PC */

    QLineEdit *le_main; /**< champ de texte principale pour créer ou supprimer */
    QLineEdit *le_change; /**< champ de texte pour modifier */

    QLabel *l_pcs; /**< Texte affichant la liste des points de collecte */
    QLabel *l_users; /**< Texte affichant la liste des utilisateurs */
    QLabel *l_admins; /**< Texte affichant la liste des administrateurs */
    QLabel *l_prods; /**< Texte affichant la liste des producteurs */

    Controller *ctrl; /**< Controlleur */
    ControllerPC *ctrlPC; /**< Controlleur */
    model::Data *data; /**< Données */

    void createButton();
private slots:
    /**
     * @brief handlerCreateUser
     */
    void handlerCreateUser();

    /**
     * @brief handlerCreatePC
     */
    void handlerCreatePC();

    /**
     * @brief handlerChangeUser
     */
    void handlerChangeUser();

    /**
     * @brief handlerChangePC
     */
    void handlerChangePC();

    /**
     * @brief handlerDeletePC
     */
    void handlerDeletePC();

    /**
     * @brief handlerCreateAdmin
     */
    void handlerCreateAdmin();

    /**
     * @brief handlerCheckPC
     */
    void handlerCheckPC();

    /**
     * @brief handlerAddProdPC
     */
    void handlerAddProdPC();

    /**
     * @brief handlerRemoveProdPC
     */
    void handlerRemoveProdPC();
public:
    /**
     * @brief Constructeur
     * @param parent
     */
    MainWindow(QWidget *parent = 0);

    /**
     * Destructeur
     */
    ~MainWindow();

    /**
     * @brief Actualise la fenetre
     */
    void refresh();
};

#endif // MAINWINDOW_H
