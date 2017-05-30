/**
* @file: Lager.h
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#ifndef INC_4_LAGER_H
#define INC_4_LAGER_H
#include <iostream>
#include <list>
#include <map>
#include "Artikel.h"
#include "Artikeldialog.h"


class Lager {
public:
    Lager(std::string name, int dimension);
    Lager(int dimension);
    void addArtikel(Artikel* artikel);
    Artikel* newArtikel();
    void addNewArtikel();
    void deleteArtikel(Artikel artikel);
    void deleteArtikel(int artikelnummer);
    std::string getName() const;
    int getDimension() const;
    void bucheZugang(Artikel artikel, int menge);
    void bucheZugang(int artikelnummer, int menge);
    void bucheAbgang(Artikel artikel, int menge);
    void bucheAbgang(int artikelnummer, int menge);
    void changePreis(double prozent);
    void printLager();
    std::string toString() const;
    void printCredits();

    const map<int, Artikel *> &getLagermap() const;

private:
    int dimension;
    Artikeldialog artikeldialog;
    std::string name;
    void setName(std::string name);
    void setDimension(int dimension);
    std::map<int, Artikel*> lagermap;
};


#endif //INC_4_LAGER_H
