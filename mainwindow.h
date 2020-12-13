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
    QPushButton *b_Order;
    QPushButton *b_Deliver;
    QPushButton *b_CheckDelivery;

    QLineEdit *le_PCName;
    QLineEdit *le_PCNewName;
    QLabel *l_PCName;
    QLabel *l_PCNewName;
    QPushButton *b_CreatePC; /**< Bouton pour créer un point de collecte */
    QPushButton *b_ChangePC; /**< Bouton pour changer un point de collecte */
    QPushButton *b_DeletePC; /**< Bouton pour supprimer un point de collecte */
    QPushButton *b_CheckPC; /**< Bouton pour valider un PC */
    QPushButton *b_OpenPC;

    QLineEdit *le_UserName;
    QLineEdit *le_UserNewName;
    QLabel *l_UserName;
    QLabel *l_UserNewName;
    QPushButton *b_CreateUser; /**< Bouton pour créer un utilisateur */
    QPushButton *b_ChangeUser; /**< Bouton pour changer un utilisateur */
    QPushButton *b_DeleteUser; /**< Bouton pour supprimer un utilisateur */

    QLineEdit *le_AdminName;
    QLabel *l_AdminName;
    QPushButton *b_CreateAdmin; /**< Bouton pour créer un Admin */

    QLineEdit *le_ProdName;
    QLabel *l_ProdName;
    QPushButton *b_AddProdPC; /**< Bouton pour ajouter un Producteur a un  PC */
    QPushButton *b_RemoveProdPC; /**< Bouton pour retirer un Producteur d'un PC */

    QLineEdit *le_ProductName;
    QLineEdit *le_ProductChange;
    QLabel *l_ProductName;
    QLabel *l_ProductChange;
    QPushButton *b_AddProduct; /**< Bouton pour ajouter un Produit */
    QPushButton *b_RemoveProduct; /**< Bouton pour retirer un Produit */
    QPushButton *b_ChangePriceProduct; /**< Bouton pour modifier le prix d'un Produit */
    QPushButton *b_ChangeNameProduct; /**< Bouton pour modifier le nom d'un Produit */

    QLabel *l_pcs; /**< Texte affichant la liste des points de collecte */
    QLabel *l_users; /**< Texte affichant la liste des utilisateurs */
    QLabel *l_productor;
    QLabel *l_product;
    QLabel *l_admins; /**< Texte affichant la liste des administrateurs */
    QLabel *l_orders; /**< Texte affichant la liste des commandes */

    Controller *ctrl; /**< Controlleur */
    ControllerPC *ctrlPC; /**< Controlleur */
    model::DataDB *data; /**< Données */

    void createInterfacePC();
    void createInterfaceUser();
    void createInterfaceProd();
    void createInterfaceProduct();
    void createInterfaceAdmin();
    void createInterfaceList();

    void deleteButtons();
    void deleteLineEdits();
    void deleteLabels();
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
