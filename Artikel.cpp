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


/**
 * Hauptkonstruktor, der (private) Methoden, die auch ueberpruefen, aufruft
 * @param artikelnummer
 * @param bezeichnung
 * @param bestand
 */

Artikel::Artikel(int artikelnummer, string bezeichnung, int bestand){
    setArtikelnummer(artikelnummer);
    setBezeichnung(bezeichnung);
    setBestand(bestand);
}

//Nebenkonstruktoren, die den Hauptkonstruktor aufrufen
Artikel::Artikel(int artikelnummer, string bezeichnung):Artikel(artikelnummer, bezeichnung,0) {}
Artikel::Artikel(int artikelnummer):Artikel(artikelnummer, "Testbezeichnung",0) {} //Für Artikel, deren Name noch nicht bekannt ist/nicht feststeht
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