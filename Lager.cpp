/**
* @file: Lager.cpp
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

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

Lager::Lager(string name, int dimension) {
    setDimension(dimension);
    try {
        setName(name);
    } catch (exception e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "Unbekannter Fehler beim Erstellen des Lagers!" << endl;
    }
}

Lager::Lager(int dimension) : Lager("Testname", dimension) {}

void Lager::addArtikel(Artikel artikel) {
    if(static_cast<int>(this->lagermap.size()) < this->dimension) {
        this->lagermap.insert(pair<int, Artikel>(artikel.getArtikelnummer(), artikel));
    } else {
        throw lagerVollExp;
    }
}

Artikel Lager::newArtikel() {
    return this->artikeldialog.artikelErstellen();
}

void Lager::addNewArtikel() {
    addArtikel(newArtikel());
}

void Lager::deleteArtikel(Artikel artikel) {
    deleteArtikel(artikel.getArtikelnummer());
}

void Lager::deleteArtikel(int artikelnummer) {
    map<int, Artikel>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
        lagermap.erase(iter);
    } else {
        cout << "Artikel nicht gefunden!" << endl;
    }
}

string Lager::getName() const{
    return this->name;
}

int Lager::getDimension() const{
    return this->dimension;
}

void Lager::bucheZugang(Artikel artikel, int menge) {
    try {
        bucheAbgang(artikel.getArtikelnummer(), menge);
    } catch (exception e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "Unbekannter Fehler beim Buchen(Zugang)!" << endl;
    }
}

void Lager::bucheZugang(int artikelnummer, int menge) {
    map<int, Artikel>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
        try {
            lagermap.at(artikelnummer).bucheZugang(menge);
        } catch (exception e) {
            cout << e.what() << endl;
        }
        catch (...) {
            cout << "Unbekannter Fehler beim Buchen(Zugang)!" << endl;
        }
    } else {
        cout << "Artikel nicht gefunden!" << endl;
    }
}

void Lager::bucheAbgang(Artikel artikel, int menge) {
    try {
        bucheAbgang(artikel.getArtikelnummer(), menge);
    } catch (exception e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "Unbekannter Fehler beim Buchen(Abgang)!" << endl;
    }
}

void Lager::bucheAbgang(int artikelnummer, int menge) {
    map<int, Artikel>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
        try {
            lagermap.at(artikelnummer).bucheAbgang(menge);
        } catch (exception e) {
            cout << e.what() << endl;
        }
        catch (...) {
            cout << "Unbekannter Fehler beim Buchen(Abgang)!" << endl;
        }
    } else {
        cout << "Artikel nicht gefunden!" << endl;
    }
}

void Lager::changePreis(double prozent) {
    for(map<int, Artikel>::iterator iter = this->lagermap.begin(); iter != this->lagermap.end(); iter++){
        double preis = iter.operator*().second.getPreis() * (prozent/100);
        iter.operator*().second.setPreis(preis);
    }
}

void Lager::printLager() {
    Artikeldialog dialog;
    cout << "Lagername: " << this->getName() << endl;
    cout << "Lagerdimension: " << this->getDimension() << endl;
    for(map<int, Artikel>::iterator iter = this->lagermap.begin(); iter != this->lagermap.end(); iter++){
        const Artikel art = iter.operator*().second;
        dialog.artikelDatenAnzeigen(art);
    }
}

string Lager::stringLager() {
    Artikeldialog dialog;
    string out = "";
    for(map<int, Artikel>::iterator iter = this->lagermap.begin(); iter != this->lagermap.end(); iter++){
        out += dialog.artikelDatenString((iter.operator*().second));
    }
    return out;
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


