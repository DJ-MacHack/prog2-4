/**
* @file: Lagerdialog.cpp
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
* Partner: Julian Bruna
*/

#include <sstream>
#include "Lagerdialog.h"

using namespace std;

/**
 * Constructor
 * @param lager
 */
Lagerdialog::Lagerdialog(Lager lager) {
    this->lager = &lager;
}

/**
 * Deconstructor
 */
Lagerdialog::~Lagerdialog() {
    delete this->lager;
    this->lager = nullptr;
}

/**
 * Constructor
 */
Lagerdialog::Lagerdialog() {
        Lager *lager = newLager();
        this->lager = lager;
}

/**
 * Creates a new Lager
 * @return
 */
Lager *Lagerdialog::newLager() {
    string name;
    int dimensionen;
    cout << "Name fuer das neue Lager: ";
    cin >> name;
    cout << endl;
    cout << "Dimensionen fuer das neue Lager: ";
    cin >> dimensionen;
    cout << endl;
    Lager *lager;
    lager = new Lager(name, dimensionen);
    return lager;
}

/**
 * Dialogue funktion
 */
void Lagerdialog::start() {
    FunktionsTyp funktion = WEITER;
    do {
        try {
            funktion = einlesenFunktion();
            ausfuehrenFunktion(funktion);
        } catch (const string &e) {
            cout << "Ausnahme: " << e << endl;
        } catch (exception& e) {
            cout << e.what() << endl;
        }
        catch (...) {
            cout << "Unbekannter Fehler Ausfuehren!" << endl;
        }

    } while (funktion != ENDE);
}

/**
 * Reads command from cin
 * @return
 */
FunktionsTyp Lagerdialog::einlesenFunktion() {
    cout << ANLEGEN << ": anlegen; "
         << ZUGANG << ": Zugang buchen; "
         << ABGANG << ": Abgang buchen; "
         << LOESCHEN << ": loeschen; "
         << PREISAENDERN << ": Preis aendern; "
         << ENDE << ": beenden -> ";
    int funktion;
    if (cin) {
        cin >> funktion;
        cout << endl;
        return static_cast<FunktionsTyp>(funktion);
    } else {
        cout << "cin error" << endl;
        return ENDE;
    }
}

/**
 * Execs command
 * @param funktion
 */
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
            cout << this->lager->toString() << endl;
            this->lager->printCredits();
            break;
        default:
            break;
    }
}
