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
enum FunktionsTyp {WEITER, ANLEGEN, ZUGANG, ABGANG,
    PREISAENDERN, LOESCHEN, ENDE = 9};
class Lagerdialog {
public:
    Lagerdialog(Lager lager);
    Lagerdialog();
    std::string toString() const;
    void start();
    FunktionsTyp einlesenFunktion();
    void ausfuehrenFunktion(FunktionsTyp funktion);

private:
    Lager lager = Lager("Init", 199);
    Lager newLager();

};


#endif //INC_4_LAGERDIALOG_H
