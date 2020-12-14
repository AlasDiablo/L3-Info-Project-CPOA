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
         * @brief getUserSize récupere le nombre d'utilisateur
         * @return le nombre d'utilisateur
         */
        unsigned int getUserSize();

        /**
         * @brief getUser récupere l'utilisateur avec le nom name
         * @param name le nom
         * @re+turn l'utilisateur
         */
        model::User getUser(QString name);

        /**
         * @brief getUsers récupere une liste des utilisateurs
         * @return une liste des utilisateurs
         */
        std::vector<model::User> getUsers();

        /**
         * @brief getPCSize récupere le nombre de point de collecte
         * @return le nombre de point de collecte
         */
        unsigned int getPCSize();

        /**
         * @brief getPC récupere le point de collecte avec le nom name
         * @param name le nom
         * @return le point de collecte
         */
        model::PC getPC(QString name);

        /**
         * @brief getPCs récupere une liste des points de collecte
         * @return une liste des points de collecte
         */
        std::vector<model::PC> getPCs();

        /**
         * @brief addUser ajoute un utilisateur
         * @param u l'utilisateur
         */
        void addUser(User u);

        /**
         * @brief addPC ajoute un point de collecte
         * @param p le point de collecte
         */
        void addPC(PC p);

        /**
         * @brief removeUser retire l'utilisateur avec le nom name
         * @param name le nom
         */
        void removeUser(QString name);

        /**
         * @brief removePC retire le point de collecte avec le nom name
         * @param name le nom
         */
        void removePC(QString name);

        /**
         * @brief addAdmin ajoute un administrateur
         * @param a l'administrateur à ajouter
         */
        void addAdmin(model::Admin a);

        /**
         * @brief removeAdmin supprime un administrateur
         * @param name le nom de l'administrateur à supprimer
         */
        void removeAdmin(QString name);

        /**
         * @brief getAdmin récupere un administrateur
         * @param name le nom de l'administrateur
         * @return l'administrateur
         */
        model::Admin getAdmin(QString name);

        /**
         * @brief getAdmins retourne la liste des administrateurs
         * @return la liste des administrateurs
         */
        std::vector<model::Admin> getAdmins();

        /**
         * @brief changePC change le nom d'un pc, sont check ou si il est ouvert
         * @param name nom du pc a mettre a jour
         * @param nouveau paramettre du pc
         */
        void changePC(QString name,  model::PC newPC);

        /**
         * @brief changeUser change le nom d'un utilisateur
         * @param name nom de l'utilisateur
         * @param newName nouveau nom d'utilisateur
         */
        void changeUser(QString name, QString newName);

        /**
         * @brief changeAdmin change le nom d'un admin
         * @param name nom de l'admin
         * @param newName nouveau nom d'admin
         */
        void changeAdmin(QString name, QString newName);

        /**
         * @brief addProductor ajout d'un producteur
         * @param pc pc lié a un producteur
         * @param productor producteur a mettre à jour
         */
        void addProductor(model::PC pc, model::Productor productor);

        /**
         * @brief removeProductor supprestion d'un producteur
         * @param pc pc lié a un producteur
         * @param productor produteur a supprimé
         */
        void removeProductor(model::PC pc, model::Productor productor);

        /**
         * @brief changeProductor change le nom du producteur
         * @param pc pc lié a un producteur
         * @param productor producteur original
         * @param newProductor nouveau paramettre du producteur
         */
        void changeProductor(model::PC pc, model::Productor productor, model::Productor newProductor);

        /**
         * @brief getProductors renvoie un liste de tous les producteur
         * @param pc pc lié au producteur
         * @return
         */
        std::vector<model::Productor> getProductors(model::PC pc);

        /**
         * @brief addProduct ajout d'un produit
         * @param pc pc lié au produit
         * @param product produit a ajouté
         */
        void addProduct(model::PC pc, model::Product product);

        /**
         * @brief removeProduct suppretion d'un produit
         * @param pc pc lié au produit
         * @param product produit a supprimé
         */
        void removeProduct(model::PC pc, model::Product product);

        /**
         * @brief changeProduct change le nom et le prix du produit
         * @param pc pc lié au produit
         * @param product ancient produit
         * @param newProduct nouveaux paramettre du produit
         */
        void changeProduct(model::PC pc, model::Product product, model::Product newProduct);

        /**
         * @brief getProducts renvoie un liste des produit assosier a un pc
         * @param pc pc lié au produit
         * @return liste des produit lié au pc
         */
        std::vector<model::Product> getProducts(model::PC pc);

        /**
         * @brief getProducts renvoie un liste des produit assosier a un pc et a un producteur
         * @param pc pc lié au produit
         * @param productor producteur lié au produit
         * @return liste des produit lié au pc et au producteur
         */
        std::vector<model::Product> getProducts(model::PC pc, model::Productor productor);

        /**
         * @brief addOrder ajout d'une commande
         * @param order commande a jouté
         */
        void addOrder(model::Order order);

        /**
         * @brief removeOrder suppretion d'un commande
         * @param order commande a supprimé
         */
        void removeOrder(model::Order order);

        /**
         * @brief getOrders revoie la liste des commande
         * @return liste des commande
         */
        std::vector<model::Order> getOrders();


    };
}
#endif // DATADB_H
