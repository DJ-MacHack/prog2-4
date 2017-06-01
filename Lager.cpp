/**
* @file: Lager.cpp
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
* Partner: Julian Bruna
*/

#include <sstream>
#include "Lager.h"

using namespace std;


/**
 * Destructor
 */
Lager::~Lager() {
    loescheArtikel();
}

/**
 * Not needed cause of my exceptions
 */
const string Lager::LEERES_LAGER = "Leerer Name!";
const string Lager::NEGATIVE_DIM = "Negative Dimension!";
const string Lager::NULL_DIM = "Dimension muss > 0 sein!";
const string Lager::VOLLES_LAGER = "Lager ist voll!";
const string Lager::NICHT_DA = "Artikel ist nicht im Lager!";
const string Lager::SCHON_DA = "Artikel ist schon im Lager!";

/**
 * Exceptions
 */
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

class inLagerException : public exception {
    virtual const char *what() const throw() {
        return "Artikel ist schon im Lager!";
    }
} inLagerExp;

/**
 * Constructor
 * @param name
 * @param dimension
 */
Lager::Lager(string name, int dimension) {
        setDimension(dimension);
        setName(name);
}

/**
 * Copy constructor
 * @param lager
 */
Lager::Lager(const Lager& lager){
    setDimension(lager.getDimension());
    setName(lager.getName());
    map<int, Artikel*> tmp = lager.getLagermap();
    for(map<int, Artikel*>::iterator iter = tmp.begin(); iter != tmp.end(); iter++){
        addArtikel(iter.operator*().second);
    }
}

/**
 * Constructor
 * @param dimension
 */
Lager::Lager(int dimension) : Lager("Testname", dimension) {}

/**
 * Add an Artikel
 * @param artikel
 */
void Lager::addArtikel(Artikel* artikel) {
    if(static_cast<int>(this->lagermap.size()) < this->dimension) {
        map<int, Artikel*>::iterator iter = this->lagermap.find(artikel->getArtikelnummer());
        if (iter == lagermap.end()) {
            this->lagermap.insert(pair<int, Artikel *>(artikel->getArtikelnummer(), artikel));
        } else {
            throw inLagerExp;
        }
    } else {
        throw lagerVollExp;
    }
}

/**
 * Create a new Artikel
 * @return
 */
Artikel* Lager::newArtikel() {
    return this->artikeldialog.artikelErstellen();
}

/**
 * Add new Artikel
 */
void Lager::addNewArtikel() {
    addArtikel(newArtikel());
}

/**
 * delete Artikel
 * @param artikel
 */
void Lager::deleteArtikel(Artikel artikel) {
    deleteArtikel(artikel.getArtikelnummer());
}

/**
 * delete Artikel
 * @param artikelnummer
 */
void Lager::deleteArtikel(int artikelnummer) {
    map<int, Artikel*>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
        lagermap.erase(iter);
        delete iter->second;
    } else {
        throw nichtDaExp;
    }
}

/**
 * Getter Name
 * @return
 */
string Lager::getName() const{
    return this->name;
}

/**
 * Getter Dimension
 * @return
 */
int Lager::getDimension() const{
    return this->dimension;
}

/**
 * Add amount of pieces to Artikel
 * @param artikel
 * @param menge
 */
void Lager::bucheZugang(Artikel artikel, int menge) {
    map<int, Artikel*>::iterator iter = this->lagermap.find(artikel.getArtikelnummer());
    if (iter != lagermap.end()) {
        bucheZugang(artikel.getArtikelnummer(), menge);
    } else {
        throw nichtDaExp;
    }

}

/**
 * Reduce amount of pieces from Artikel
 * @param artikelnummer
 * @param menge
 */
void Lager::bucheZugang(int artikelnummer, int menge) {
    map<int, Artikel*>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
            lagermap.at(artikelnummer)->bucheZugang(menge);
    } else {
        throw nichtDaExp;
    }
}

/**
 * Reduce amount of pieces from Artikel
 * @param artikel
 * @param menge
 */
void Lager::bucheAbgang(Artikel artikel, int menge) {
    map<int, Artikel*>::iterator iter = this->lagermap.find(artikel.getArtikelnummer());
    if (iter != lagermap.end()) {
        bucheAbgang(artikel.getArtikelnummer(), menge);
    } else {
        throw nichtDaExp;
    }
}

/**
 * Reduce amount of pieces from Artikel
 * @param artikelnummer
 * @param menge
 */
void Lager::bucheAbgang(int artikelnummer, int menge) {
    map<int, Artikel*>::iterator iter = this->lagermap.find(artikelnummer);
    if (iter != lagermap.end()) {
            lagermap.at(artikelnummer)->bucheAbgang(menge);
    } else {
        throw nichtDaExp;
    }
}

/**
 * Getter Lagermap
 * @return
 */
const map<int, Artikel *> &Lager::getLagermap() const {
    return lagermap;
}

/**
 * Change Preis
 * @param prozent
 */
void Lager::changePreis(double prozent) {
    for(map<int, Artikel*>::iterator iter = this->lagermap.begin(); iter != this->lagermap.end(); iter++){
        double preis = iter.operator*().second->getPreis() * ( 1 + (prozent/100));
        iter.operator*().second->setPreis(preis);
    }
}

/**
 * Print Lager in cout
 */
void Lager::printLager() {
    Artikeldialog dialog;
    cout << "Lagername: " << this->getName() << endl;
    cout << "Lagerdimension: " << this->getDimension() << endl;
    for(map<int, Artikel*>::iterator iter = this->lagermap.begin(); iter != this->lagermap.end(); iter++){
        const Artikel* art = iter.operator*().second;
        dialog.artikelDatenAnzeigen(*art);
    }
}

/**
 * Lager to string
 * @return
 */
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

/**
 * Setter Name
 * @param name
 */
void Lager::setName(string name) {
    if (name == "") {
        throw leeresLagerExp;
    } else {
        this->name = name;
    }
}

/**
 * Setter Dimension
 * @param dimension
 */
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

/**
 * Prints my awesome credits
 */
void Lager::printCredits()  {
    this->artikeldialog.credits();
}

/**
 * deletes all artikels cleanly
 */
void Lager::loescheArtikel() {
    for(map<int, Artikel*>::iterator iter = this->lagermap.begin(); iter != this->lagermap.end(); iter++){
        delete iter.operator*().second;
        iter.operator*().second = nullptr;
    }
}

/**
 * Operator =
 * @param lager
 * @return
 */
Lager& Lager::operator=(const Lager& lager){
    if(this == &lager){
        return *this;
    }

    setName(lager.getName());
    setDimension(lager.getDimension());
    loescheArtikel();
    map<int,Artikel*> tmp = lager.getLagermap();
    for(map<int, Artikel*>::iterator iter = tmp.begin(); iter != tmp.end(); iter++){
        addArtikel(iter.operator*().second);
    }

    return *this;
}

