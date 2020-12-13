#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @file mainwindow.h
 * @brief MainWindow Class
 * @author Safyrus
 * @version 1.7
 */

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
    QLineEdit *le_PCName; /**< Champ de texte pour entrer le nom d'un PC */
    QLineEdit *le_PCNewName; /**< Champ de texte pour entrer le nouveau nom d'un PC */
    QLabel *l_PCName; /**< Label pour le champ de text PCName */
    QLabel *l_PCNewName; /**< Label pour le champ de text PCNewName */
    QPushButton *b_CreatePC; /**< Bouton pour créer un point de collecte */
    QPushButton *b_ChangePC; /**< Bouton pour changer un point de collecte */
    QPushButton *b_DeletePC; /**< Bouton pour supprimer un point de collecte */
    QPushButton *b_CheckPC; /**< Bouton pour valider un PC */
    QPushButton *b_OpenPC;

    QLineEdit *le_UserName; /**< Champ de texte pour entrer le nom d'un Utilisateur */
    QLineEdit *le_UserNewName; /**< Champ de texte pour entrer le nouveau nom d'un Utilisateur */
    QLabel *l_UserName; /**< Label pour le champ de text UserName */
    QLabel *l_UserNewName; /**< Label pour le champ de text UserNewName */
    QPushButton *b_CreateUser; /**< Bouton pour créer un utilisateur */
    QPushButton *b_ChangeUser; /**< Bouton pour changer un utilisateur */
    QPushButton *b_DeleteUser; /**< Bouton pour supprimer un utilisateur */

    QLineEdit *le_AdminName; /**< Champ de texte pour entrer le nom d'un Administrateur */
    QLabel *l_AdminName;
    QPushButton *b_CreateAdmin; /**< Bouton pour créer un Admin */

    QLineEdit *le_ProdName; /**< Champ de texte pour entrer le nom d'un Producteur */
    QLabel *l_ProdName; /**< Label pour le champ de text ProdName */
    QPushButton *b_AddProdPC; /**< Bouton pour ajouter un Producteur a un  PC */
    QPushButton *b_RemoveProdPC; /**< Bouton pour retirer un Producteur d'un PC */

    QLineEdit *le_ProductName; /**< Champ de texte pour entrer le nom d'un Produit */
    QLineEdit *le_ProductChange; /**< Champ de texte pour entrer un changement d'un Produit */
    QLabel *l_ProductName; /**< Label pour le champ de text ProductName */
    QLabel *l_ProductChange; /**< Label pour le champ de text ProductChange */
    QPushButton *b_AddProduct; /**< Bouton pour ajouter un Produit */
    QPushButton *b_RemoveProduct; /**< Bouton pour retirer un Produit */
    QPushButton *b_ChangePriceProduct; /**< Bouton pour modifier le prix d'un Produit */
    QPushButton *b_ChangeNameProduct; /**< Bouton pour modifier le nom d'un Produit */

    QPushButton *b_Order; /**< Bouton pour creer une Commande */

    QLabel *l_pcs; /**< Texte affichant la liste des points de collecte */
    QLabel *l_users; /**< Texte affichant la liste des utilisateurs */
    QLabel *l_productor; /**< Texte affichant la liste des producteurs */
    QLabel *l_product; /**< Texte affichant la liste des produits */
    QLabel *l_admins; /**< Texte affichant la liste des administrateurs */
    QLabel *l_orders; /**< Texte affichant la liste des commandes */

    Controller *ctrl; /**< Controlleur */
    ControllerPC *ctrlPC; /**< Controlleur */
    model::DataDB *data; /**< Données */

    /**
     * @brief createInterfacePC
     */
    void createInterfacePC();

    /**
     * @brief createInterfaceUser
     */
    void createInterfaceUser();

    /**
     * @brief createInterfaceProd
     */
    void createInterfaceProd();

    /**
     * @brief createInterfaceProduct
     */
    void createInterfaceProduct();

    /**
     * @brief createInterfaceAdmin
     */
    void createInterfaceAdmin();

    /**
     * @brief createInterfaceList
     */
    void createInterfaceList();

    /**
     * @brief createInterfaceOther
     */
    void createInterfaceOther();

    /**
     * @brief deleteButtons
     */
    void deleteButtons();

    /**
     * @brief deleteLineEdits
     */
    void deleteLineEdits();

    /**
     * @brief deleteLabels
     */
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

    /**
     * @brief handlerOrder
     */
    void handlerOrder();

    /**
     * @brief handlerOpenPC
     */
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
