/**
* @file: Lager.cpp
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include <sstream>
#include "Lager.h"

using namespace std;

class LeereException : public exception {
    virtual const char *what() const throw() {
        return "Leerer Name!";
    }
} leeresLagerExp;

class negativeException : public exception {
    virtual const char *what() const throw() {
        return "Negative Dimension!";
    }
} negDimExp;

class nullException : public exception {
    virtual const char *what() const throw() {
        return "Dimension muss > 0 sein!";
    }
} nullDimExp;

class lagerVollException : public exception {
    virtual const char *what() const throw() {
        return "Lager ist voll!";
    }
} lagerVollExp;

class nichtDaException : public exception {
    virtual const char *what() const throw() {
        return "Artikel ist nicht im Lager!";
    }
} nichtDaExp;

Lager::Lager(string name, int dimension) {
    setDimension(dimension);
        setName(name);
}

Lager::Lager(int dimension) : Lager("Testname", dimension) {}

void Lager::addArtikel(Artikel* artikel) {
    if(static_cast<int>(this->lagermap.size()) < this->dimension) {
        this->lagermap.insert(pair<int, Artikel*>(artikel->getArtikelnummer(), artikel));
    } else {
        throw lagerVollExp;
    }
}

Artikel* Lager::newArtikel() {
    return this->artikeldialog.artikelErstellen();
}

void Lager::addNewArtikel() {
    addArtikel(newArtikel());
}

void Lager::deleteArtikel(Artikel artikel) {
    deleteArtikel(artikel.getArtikelnummer());
}

void Lager::deleteArtikel(int artikelnummer) {
    map<int, Artikel*>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
        lagermap.erase(iter);
        delete iter->second;
    } else {
        throw nichtDaExp;
    }
}

string Lager::getName() const{
    return this->name;
}

int Lager::getDimension() const{
    return this->dimension;
}

void Lager::bucheZugang(Artikel artikel, int menge) {

        bucheAbgang(artikel.getArtikelnummer(), menge);

}

void Lager::bucheZugang(int artikelnummer, int menge) {
    map<int, Artikel*>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
            lagermap.at(artikelnummer)->bucheZugang(menge);
    } else {
        throw nichtDaExp;
    }
}

void Lager::bucheAbgang(Artikel artikel, int menge) {
        bucheAbgang(artikel.getArtikelnummer(), menge);
}

void Lager::bucheAbgang(int artikelnummer, int menge) {
    map<int, Artikel*>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
        lagermap.at(artikelnummer)->bucheAbgang(menge);
    }
    else {
            throw nichtDaExp;
        }
}

const map<int, Artikel *> &Lager::getLagermap() const {
    return lagermap;
}

void Lager::changePreis(double prozent) {
    for(map<int, Artikel*>::iterator iter = this->lagermap.begin(); iter != this->lagermap.end(); iter++){
        double preis = iter.operator*().second->getPreis() * (prozent/100);
        iter.operator*().second->setPreis(preis);
    }
}

void Lager::printLager() {
    Artikeldialog dialog;
    cout << "Lagername: " << this->getName() << endl;
    cout << "Lagerdimension: " << this->getDimension() << endl;
    for(map<int, Artikel*>::iterator iter = this->lagermap.begin(); iter != this->lagermap.end(); iter++){
        const Artikel* art = iter.operator*().second;
        dialog.artikelDatenAnzeigen(*art);
    }
}

string Lager::toString() const {
    ostringstream out;
    out << "Lager: " << this->getName() << '\n';
    out << "Dimension: " << this->getDimension() << '\n' << '\n';

    for (map<int, Artikel*>::const_iterator iter = this->getLagermap().begin(); iter != this->getLagermap().end(); iter++) {
        out << "Artikelname: " << iter.operator*().second->getBezeichnung() << '\n';
        out << "Artikelnummer: " << iter.operator*().second->getArtikelnummer() << '\n';
        out << "Artikelbestand: " << iter.operator*().second->getBestand() << '\n';
        out << "Artikelpreis: " << iter.operator*().second->getPreis() << '\n' << '\n';
    } out << endl;

    return out.str();
}

void Lager::setName(string name) {
    if (name == "") {
        throw leeresLagerExp;
    } else {
        this->name = name;
    }
}

void Lager::setDimension(int dimension) {
    if (dimension == 0) {
        throw nullDimExp;
    } else {
        if (dimension < 0) {
            throw negDimExp;
        } else {
            this->dimension = dimension;
        }
    }
}

void Lager::printCredits()  {
    this->artikeldialog.credits();
}


