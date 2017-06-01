//
// Created by DJ_MacHack on 09.05.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#ifndef INC_2_ARTIKELDIALOG_H
#define INC_2_ARTIKELDIALOG_H

#include "Artikel.h"
#include <vector>
#include <iostream>

class Artikeldialog {
public:
    void artikelDatenAnzeigen(const Artikel& artikel);
    string auswahl();
    Artikel* artikelErstellen();
    void credits();

    virtual ~Artikeldialog();

private:
    vector<string>split(string str, char delimiter);
};


#endif //INC_2_ARTIKELDIALOG_H
