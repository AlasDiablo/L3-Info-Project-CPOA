/**
 * @file main.cpp
 * @brief main function
 * @author Safyrus
 * @version 1.3
 */

#include "mainwindow.h"
#include <QApplication>

/**
 * @brief Fonction principale du programe
 * @param argc nombre d'argument
 * @param argv tableau d'argument
 * @return un code d'erreur
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
