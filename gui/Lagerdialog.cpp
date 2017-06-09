/**
* @file: Lagerdialog.cpp
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include <sstream>
#include <QInputDialog>
#include <QString>
#include <QDir>
#include "Lagerdialog.h"
using namespace std;

/**
 * Deconstructor
 */
Lagerdialog::~Lagerdialog() {
    delete this->lager;
    this->lager = nullptr;
}

Lagerdialog::Lagerdialog(Lager* lager, MainWindow* wd){
    this->lager = lager;
    this->wd = wd;
}

Lager* Lagerdialog::getLager() const {
    return this->lager;
}

Lager* Lagerdialog::newLager(){

//    int dimensionen = 12;
//    //cout << "Name fuer das neue Lager: ";
//    QString qs = QString("Name fuer das neue Lager: ");
//    this->wd->getTextBrowser()->setText(qs);
//    //cin >> name;
//    string name = "Test";
//    name = this->wd->getInputString();

//    if(name == ""){
//        name = "empty";
//    }
//    //cout << endl;
//    // cout << "Dimensionen fuer das neue Lager: ";
//    qs = QString("Dimensionen fuer das neue Lager: ");
//    this->ui->getTextBrowser()->setText(qs);
//    //cin >> dimensionen;
//    //cout << endl;
//    dimensionen = this->ui->getInputInt();
    Lager* lager = new Lager("name", 1);
    return lager;
}

void Lagerdialog::start(){
    FunktionsTyp funktion = WEITER;
    do {
        try {
            funktion = einlesenFunktion();
            ausfuehrenFunktion(funktion);
            if(funktion == AUSGEBEN){
                break;
            }
        } catch (const string& e) {
            string text = "Ausnahme: " + e;
            this->wd->getTextBrowser2()->setText(QString::fromStdString(text));
        } catch(exception& e) {
            this->wd->getTextBrowser2()->setText(QString::fromStdString(e.what()));
        } catch(...) {
            this->wd->getTextBrowser2()->setText(QString::fromStdString("Unbekannter Fehler beim Lagerdialog."));
        }
    } while (funktion != ENDE);
}

FunktionsTyp Lagerdialog::einlesenFunktion() {
   ostringstream out;
   out <<  "1";
   out << ": anlegen; " << '\n' << "2" << ": Zugang buchen; "
    << '\n'    << "3" << ": Abgang buchen; "
       << '\n'  << "4" << ": loeschen; "
         << '\n'<< "5" << ": Preis aendern; "
         << '\n' << "6" << ": Lager ausgeben; "
         << '\n'<< "9" << ": beenden ";
  wd->getTextBrowser()->setText(QString::fromStdString(out.str()));
    int funktion = QInputDialog::getInt(0, "Auswahl", "Deine Wahl:", 1);

        return static_cast<FunktionsTyp>(funktion);

}

void Lagerdialog::ausfuehrenFunktion(FunktionsTyp funktion) {
    int artikelnummer, menge;
    string name;
    double betrag;

    switch (funktion) {
        case ANLEGEN:
            //this->lager->addNewArtikel();
        bool ok;
        name = QInputDialog::getText(0, "Rename Label", "Artikelname:", QLineEdit::Normal,
                "DEFAULT TEXT", &ok).toStdString();
//        name = QInputDialog::getText(this->wd, this->wd->tr("QInputDialog::getText()"),
//                                     this->wd, this->wd->tr("Name des Artikels:"), QLineEdit::Normal,
//                                     QDir::home().dirName(), &ok).toStdString();
        artikelnummer = QInputDialog::getInt(0, "Artikelnummer", "Artikelnummer des Artikels:", 1000);
        menge = QInputDialog::getInt(0, "Menge", "Menge des Artikels :", 1);

        betrag = QInputDialog::getDouble(0, "Preis", "Preis des Artikels :", 1, -2147485647, 2147485647, 4);
       // Artikel* neu = new Artikel(artikelnummer,name,menge,betrag);
        this->lager->addArtikel(new Artikel(artikelnummer,name,menge,betrag));
        break;
        case ZUGANG:
            artikelnummer = QInputDialog::getInt(0, "Artikelnummer", "Artikelnummer des Artikels:", 1);
            menge = QInputDialog::getInt(0, "Zugangsmenge", "Zugangsmenge des Artikels :", 1);
            this->lager->bucheZugang(artikelnummer, menge);
        break;
        case ABGANG:
        artikelnummer = QInputDialog::getInt(0, "Artikelnummer", "Artikelnummer des Artikels:", 1);
        menge = QInputDialog::getInt(0, "Abgangsmenge", "Abgangsmenge des Artikels :", 1);
            this->lager->bucheAbgang(artikelnummer, menge);
        break;
        case LOESCHEN:
            artikelnummer = QInputDialog::getInt(0, "Artikelnummer", "Artikelnummer des Artikels:", 1);
            this->lager->deleteArtikel(artikelnummer);
        break;
        case PREISAENDERN:
            betrag = QInputDialog::getInt(0, "Prozenz", "Prozentuale Preisänderung:", 1);
            this->lager->changePreis(betrag);
        break;
        case AUSGEBEN:
        this->wd->getTextBrowser()->setText(QString::fromStdString(this->lager->toString()));
        break;
        case ENDE:
        this->wd->getTextBrowser()->setText(QString::fromStdString(this->lager->toString()));
        this->wd->close();
        break;
        default:
            //ausfuehrenFunktion(einlesenFunktion()); //korrekt?
        break;
    }
}
