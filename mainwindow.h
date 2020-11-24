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

    QLineEdit *le_UserName; /**< champ de texte pour le nom d'utilisateur */
    QLineEdit *le_PCName; /**< champ de texte pour le point de collecte */
    QLineEdit *le_ChangeUserName; /**< champ de texte pour le nom d'utilisateur */
    QLineEdit *le_ChangePCName; /**<  */
    QLineEdit *le_AdminName; /**<  */

    QLabel *l_pcs; /**< Texte affichant la liste des points de collecte */
    QLabel *l_users; /**< Texte affichant la liste des utilisateurs */
    QLabel *l_admins; /**< Texte affichant la liste des administrateurs */

    Controller *ctrl; /**< Controlleur */
    ControllerPC *ctrlPC; /**< Controlleur */
    model::Data *data; /**< Données */
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
