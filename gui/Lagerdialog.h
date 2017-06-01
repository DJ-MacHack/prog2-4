/**
* @file: Lagerdialog.h
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#ifndef INC_4_LAGERDIALOG_H
#define INC_4_LAGERDIALOG_H


#include "Lager.h"
#include <QTextBrowser>
#include <mainwindow.h>
#include <ui_mainwindow.h>

enum FunktionsTyp {WEITER = 0, ANLEGEN = 1, ZUGANG = 2, ABGANG = 3,
     LOESCHEN = 4, PREISAENDERN = 5, AUSGEBEN = 6, ENDE = 9};
class Lagerdialog {
public:
    Lagerdialog(Lager* lager, MainWindow* wd);
    void start();
    FunktionsTyp einlesenFunktion();
    void ausfuehrenFunktion(FunktionsTyp funktion);
    MainWindow* wd;
    ~Lagerdialog();

private:
    Lager* lager;
    Lager* newLager();

};


#endif //INC_4_LAGERDIALOG_H
