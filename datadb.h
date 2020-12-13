#ifndef DATADB_H
#define DATADB_H

#include <QSqlDatabase>
#include "user.h"
#include "pc.h"
#include "admin.h"
#include "order.h"

#include <vector>

namespace model {
    class DataDB
    {
    private:
        QSqlDatabase db;
    public:
        DataDB();

        /**
         * @brief récupere le nombre d'utilisateur
         * @return le nombre d'utilisateur
         */
        unsigned int getUserSize();

        /**
         * @brief récupere l'utilisateur avec le nom name
         * @param name le nom
         * @re+turn l'utilisateur
         */
        model::User getUser(QString name);

        /**
         * @brief récupere une liste des utilisateurs
         * @return une liste des utilisateurs
         */
        std::vector<model::User> getUsers();

        /**
         * @brief récupere le nombre de point de collecte
         * @return le nombre de point de collecte
         */
        unsigned int getPCSize();

        /**
         * @brief récupere le point de collecte avec le nom name
         * @param name le nom
         * @return le point de collecte
         */
        model::PC getPC(QString name);

        /**
         * @brief récupere une liste des points de collecte
         * @return une liste des points de collecte
         */
        std::vector<model::PC> getPCs();

        /**
         * @brief ajoute un utilisateur
         * @param u l'utilisateur
         */
        void addUser(User u);

        /**
         * @brief ajoute un point de collecte
         * @param p le point de collecte
         */
        void addPC(PC p);

        /**
         * @brief retire l'utilisateur avec le nom name
         * @param name le nom
         */
        void removeUser(QString name);

        /**
         * @brief retire le point de collecte avec le nom name
         * @param name le nom
         */
        void removePC(QString name);

        /**
         * @brief ajoute un administrateur
         * @param a l'administrateur à ajouter
         */
        void addAdmin(model::Admin a);

        /**
         * @brief supprime un administrateur
         * @param name le nom de l'administrateur à supprimer
         */
        void removeAdmin(QString name);

        /**
         * @brief récupere un administrateur
         * @param name le nom de l'administrateur
         * @return l'administrateur
         */
        model::Admin getAdmin(QString name);

        /**
         * @brief retourne la liste des administrateurs
         * @return la liste des administrateurs
         */
        std::vector<model::Admin> getAdmins();


        void changePC(QString name,  model::PC newPC);
        void changeUser(QString name, QString newName);
        void changeAdmin(QString name, QString newName);

        void addProductor(model::PC pc, model::Productor productor);
        void removeProductor(model::PC pc, model::Productor productor);
        void changeProductor(model::PC pc, model::Productor productor, model::Productor newProductor);
        std::vector<model::Productor> getProductors(model::PC pc);

        void addProduct(model::PC pc, model::Product product);
        void removeProduct(model::PC pc, model::Product product);
        void changeProduct(model::PC pc, model::Product product, model::Product newProduct);
        std::vector<model::Product> getProducts(model::PC pc);
        std::vector<model::Product> getProducts(model::PC pc, model::Productor productor);

        void addOrder(model::Order order);
        void removeOrder(model::Order order);
        void changeOrder(model::Order order, model::Order newOrder);
        std::vector<model::Order> getOrders();


    };
}
#endif // DATADB_H
