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

class Lagerdialog {
public:
    Lagerdialog(Lager lager);
    Lagerdialog();
    std::string toString() const;
    void start();

private:
    Lager* lager;
    Lager newLager();

};


#endif //INC_4_LAGERDIALOG_H
