/**
* @file: Lagerdialog.h
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
* Partner: Julian Bruna
*/

#ifndef INC_4_LAGERDIALOG_H
#define INC_4_LAGERDIALOG_H


#include "Lager.h"
enum FunktionsTyp {WEITER, ANLEGEN, ZUGANG, ABGANG,
    PREISAENDERN, LOESCHEN, ENDE = 9};
class Lagerdialog {
public:
    Lagerdialog(Lager lager);
    Lagerdialog();
    void start();
    FunktionsTyp einlesenFunktion();
    void ausfuehrenFunktion(FunktionsTyp funktion);

    virtual ~Lagerdialog();

private:
    Lager* lager;
    Lager* newLager();

};


#endif //INC_4_LAGERDIALOG_H
