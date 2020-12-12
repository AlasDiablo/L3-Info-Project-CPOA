#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @file mainwindow.h
 * @brief MainWindow Class
 * @author Safyrus
 * @version 1.3
 */

#include "user.h"
#include "pc.h"
#include "datadb.h"
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
    QPushButton *b_DeleteUser; /**< Bouton pour supprimer un utilisateur */
    QPushButton *b_CreateAdmin; /**< Bouton pour créer un Admin */
    QPushButton *b_CheckPC; /**< Bouton pour valider un PC */
    QPushButton *b_AddProdPC; /**< Bouton pour ajouter un Producteur a un  PC */
    QPushButton *b_RemoveProdPC; /**< Bouton pour retirer un Producteur d'un PC */
    QPushButton *b_AddProduct; /**< Bouton pour ajouter un Produit */
    QPushButton *b_RemoveProduct; /**< Bouton pour retirer un Produit */
    QPushButton *b_ChangePriceProduct; /**< Bouton pour modifier le prix d'un Produit */
    QPushButton *b_ChangeNameProduct; /**< Bouton pour modifier le nom d'un Produit */
    QPushButton *b_Order;
    QPushButton *b_Deliver;
    QPushButton *b_CheckDelivery;
    QPushButton *b_OpenPC;

    QLineEdit *le_main; /**< champ de texte principale pour créer ou supprimer */
    QLineEdit *le_change; /**< champ de texte pour modifier */
    QLineEdit *le_change2; /**< champ de texte pour modifier */
    QLineEdit *le_change3; /**< champ de texte pour modifier */

    QLabel *l_pcs; /**< Texte affichant la liste des points de collecte */
    QLabel *l_users; /**< Texte affichant la liste des utilisateurs */
    QLabel *l_admins; /**< Texte affichant la liste des administrateurs */
    QLabel *l_orders; /**< Texte affichant la liste des commandes */

    Controller *ctrl; /**< Controlleur */
    ControllerPC *ctrlPC; /**< Controlleur */
    model::DataDB *data; /**< Données */

    void createButtons();
    void deleteButtons();
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
     * @brief handlerDeleteUser
     */
    void handlerDeleteUser();

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

    /**
     * @brief handlerAddProduct
     */
    void handlerAddProduct();

    /**
     * @brief handlerRemoveProduct
     */
    void handlerRemoveProduct();

    /**
     * @brief handlerChangePriceProduct
     */
    void handlerChangePriceProduct();

    /**
     * @brief handlerChangeNameProduct
     */
    void handlerChangeNameProduct();

    void handlerOrder();
    void handlerDeliver();
    void handlerCheckDelivery();
    void handlerOpenPC();
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
