/**
* @file: Lagerdialog.cpp
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include <sstream>
#include "Lagerdialog.h"
using namespace std;

Lagerdialog::Lagerdialog(Lager lager){
    this->lager = &lager;
}

Lagerdialog::Lagerdialog(){
    Lager* lager = newLager();
    this->lager = lager;
}

Lager* Lagerdialog::newLager(){
    string name;
    int dimensionen;
    cout << "Name fuer das neue Lager: ";
    cin >> name;
    cout << endl;
    cout << "Dimensionen fuer das neue Lager: ";
    cin >> dimensionen;
    cout << endl;
    Lager* lager = new Lager(name, dimensionen);
    return lager;
}

void Lagerdialog::start(){
    FunktionsTyp funktion;
    do {
        try {
            funktion = einlesenFunktion();
            ausfuehrenFunktion(funktion);
        } catch (const string& e) {
            cout << "Ausnahme: " << e << endl;
        }
    } while (funktion != ENDE);
}

FunktionsTyp Lagerdialog::einlesenFunktion() {
    cout << ANLEGEN << ": anlegen; "
         << ZUGANG << ": Zugang buchen; "
         << ABGANG << ": Abgang buchen; "
         << LOESCHEN << ": loeschen; "
         << PREISAENDERN << ": Preis aendern; "
         << ENDE << ": beenden -> ";
    int funktion;
    if(cin) {
        cin >> funktion;
        cout << endl;
        return static_cast<FunktionsTyp>(funktion);
    } else {
        cout << "cin error" << endl;
        return ENDE;
    }
}

void Lagerdialog::ausfuehrenFunktion(FunktionsTyp funktion) {
    int artikelnummer, menge;
    double betrag;
    switch (funktion) {
        case ANLEGEN:
            this->lager->addNewArtikel();
            break;
        case ZUGANG:
            cout << "Artikelnummer: ";
            cin >> artikelnummer;
            cout << endl << "Zugangsmenge : ";
            cin >> menge;
            cout << endl;
            this->lager->bucheZugang(artikelnummer, menge);
            break;
        case ABGANG:
            cout << "Artikelnummer: ";
            cin >> artikelnummer;
            cout << endl << "Abgangsmenge : ";
            cin >> menge;
            cout << endl;
            this->lager->bucheAbgang(artikelnummer, menge);
            break;
        case LOESCHEN:
            cout << "Artikelnummer: ";
            cin >> artikelnummer;
            cout << endl;
            this->lager->deleteArtikel(artikelnummer);
            break;
        case PREISAENDERN:
            cout << endl << "Prozentuale Preisänderung: ";
            cin >> betrag;
            cout << endl;
            this->lager->changePreis(betrag);
            break;
        case ENDE:
            this->lager->printLager();
            this->lager->printCredits();
            break;
        default:
            //ausfuehrenFunktion(einlesenFunktion()); //korrekt?
            break;
    }
}

string Lagerdialog::toString() const {
    //ostringstream o;
    //o << "Lager: " << name << '\n';
   // for (int i = 0; i < this->lager.getDimension(); i++) { o << kontoTab[i]->toString() << '\n'; } o << endl;
    string out;
    out += "Lager: " + this->lager->getName();
    out += '\n';
    out += this->lager->stringLager();
    return out;
}