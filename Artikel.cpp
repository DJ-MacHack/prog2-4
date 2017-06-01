//
// Created by DJ_MacHack on 09.05.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include "Artikel.h"

//Exceptions mit ihren Aussagen
class StellenException: public exception {
    virtual const char *what() const throw() {
        return "Artikelnummer nicht vierstellig!";
    }
} stellenexp;

class LeereException: public exception {
    virtual const char *what() const throw() {
        return "Leerer Name!";
    }
} leereexp;

class negativeException: public exception {
    virtual const char *what() const throw() {
        return "Negative Menge!";
    }
} negativeexp;

class keineException: public exception {
    virtual const char *what() const throw() {
        return "Keine Menge!";
    }
} keineexp;

class niedrigException: public exception {
    virtual const char *what() const throw() {
        return "Zu niedriger Bestand!";
    }
} niedrigexp;

class preisException: public exception {
    virtual const char *what() const throw() {
        return "Preis kann nicht unter 0 Euro sein!";
    }
} preisexp;

/**
 * Copyconstructor
 * @param artikel
 */
Artikel::Artikel(const Artikel& artikel){
    setArtikelnummer(artikel.getArtikelnummer());
    setBestand(artikel.getBestand());
    setPreis(artikel.getPreis());
    setBezeichnung(artikel.getBezeichnung());
}

/**
 * Hauptkonstruktor, der (private) Methoden, die auch ueberpruefen, aufruft
 * @param artikelnummer
 * @param bezeichnung
 * @param bestand
 */

Artikel::Artikel(int artikelnummer, string bezeichnung, int bestand, double preis){
    setArtikelnummer(artikelnummer);
    setBezeichnung(bezeichnung);
    setBestand(bestand);
    setPreis(preis);
}

//Nebenkonstruktoren, die den Hauptkonstruktor aufrufen
Artikel::Artikel(int artikelnummer, string bezeichnung):Artikel(artikelnummer, bezeichnung,0,0.0) {}
Artikel::Artikel(int artikelnummer):Artikel(artikelnummer, "Testbezeichnung",0, 0.0) {} //Für Artikel, deren Name noch nicht bekannt ist/nicht feststeht
/**
 * Gibt den aktuellen Bestand aus
 *@return bestand
 */
int Artikel::getBestand() const {
    return this->bestand;
}

/**
 * Gibt die Artikelnummer aus
 *@return artikelnummer
 */
int Artikel::getArtikelnummer() const {
    return this->artikelnummer;
}

/**
 * Gibt die aktuelle Bezeichnung aus
 *@return bezeichnung
 */
string Artikel::getBezeichnung() const {
    return this->bezeichnung;
}

/**
 * Setzt die aktuelle Bezeichnung
 * @param name
 */
void Artikel::setBezeichnung(string name) {
    if(name==""){
        throw leereexp;
    }
    this->bezeichnung=name;
}

/**
 * Bucht einen Zugang der Menge ab und überprüft ob menge korrekt ist
 * @param menge
 */
void Artikel::bucheZugang(int menge) {
    if(menge < 0){
        throw negativeexp;
    }
    if(!(menge > 0)){
        throw keineexp;
    }
    this->bestand += menge;
}

/**
 * Bucht einen Abgang der Menge ab und überprüft ob menge korrekt ist
 * @param menge
 */
void Artikel::bucheAbgang(int menge) {
    if(this->bestand < menge){
        throw niedrigexp;
    }
    if(menge < 0){
        throw negativeexp;
    }
    if(!(menge > 0)){
        throw keineexp;
    }
    this->bestand -= menge;
}

/**
 * Setzt und überprüft, ist private, nur für Konstruktor
 * @param artikelnummer
 */
void Artikel::setArtikelnummer(int artikelnummer){
    if(artikelnummer > 9999 || artikelnummer < 1000){
        throw stellenexp;
    }
    this->artikelnummer=artikelnummer;
}

/**
 * Setzt und überprüft Bestand, ist private, nur für Konstruktor
 * @param menge
 */
void Artikel::setBestand(int menge) {
    if(menge < 0){
        throw niedrigexp;
    }
    this->bestand=menge;
}

/**
 * Getter fuer Preis
 * @return
 */
double Artikel::getPreis() const {
    return this->preis;
}

/**
 * Setter fuer Preis
 * @param preis
 */
void Artikel::setPreis(double preis) {
    if(preis < 0.0){
        throw preisexp;
    } else {
        this->preis = preis;
    }
}

/**
 * Operator =
 * @param artikel
 * @return
 */
Artikel& Artikel::operator=(const Artikel& artikel){
    if(this==&artikel){
        return *this;
    }
    setBezeichnung(artikel.getBezeichnung());
    setPreis(artikel.getPreis());
    setBestand(artikel.getBestand());
    setArtikelnummer(artikel.getArtikelnummer());
    return *this;
}
