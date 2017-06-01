//
// Created by DJ_MacHack on 09.05.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include <fstream>
#include<iostream>
#include <sstream>
//#include <windows.h>
#include "Artikeldialog.h"

/**
 * Default deconstructor
 */
Artikeldialog::~Artikeldialog() {}

/**
 * Gibt den Artikel in der Konsole aus
 * @param artikel
 */
void Artikeldialog::artikelDatenAnzeigen(const Artikel &artikel) {
    cout << "Artikelnummer: " << artikel.getArtikelnummer() << endl;
    cout << "Artikelbezeichnung: " << artikel.getBezeichnung() << endl;
    cout << "Artikelbestand: " << artikel.getBestand() << endl;
    cout << "Artikelpreis: " << artikel.getPreis() << endl;
}

/**
 * Auswahlmenue
 * @return input
 */
string Artikeldialog::auswahl() {
    string input;
    cout << "Auswahl der Moeglichkeiten:" << endl;
    cout << "1 Neuen Artikel erstellen" << endl;
    cout << "2 ArtikelTests starten" << endl;
    cout << "3 Programm beenden" << endl;
    cin >> input;
    return input;
}

/**
 * Erstellt Artikel aus der Benutzereingabe
 * @return neu
 */
Artikel* Artikeldialog::artikelErstellen() {
    int nummer, menge;
    double preis;
    string name;
    Artikel* wrong = new Artikel(1000);
    do {
        cout << "Ihre vierstellige Artikelnummer:" << endl;
        cin >> nummer;
        cout << endl << "Ihr Artikelname:" << endl;
        cin >> name;
        cout << endl <<  "Ihr Artikelbestand:" << endl;
        cin >> menge;
        cout << endl << "Ihr Artikelpreis:" << endl;
        cin >> preis;
        cout << endl;
        try {
            Artikel* neu = new Artikel(nummer, name, menge, preis);
            return neu;
        } catch (exception& e) {
            cout << e.what() << endl;
            if (cin) { cout << "Fehler, bitte neu Eingeben!" << endl; }
            else { cout << "Fehler bei der Eingabe!" << endl; }
        }
    } while (cin);
    return wrong;
}

/**
 * Schreibt Credits in die Konsole
 * Liest credits.txt
 * Sucht das Auge von Tux und macht es rot und blinkend
 * Hintergrund schwarz
 * in Kommentaren Code für Windows
 */
void Artikeldialog::credits() {
    std::ifstream inFile ("credits.txt");
    std::string input = "";
    //inFile.open("credits.txt");
    if (inFile.is_open()) {
        while (getline (inFile,input)) {
            if(input.find("Q") != std::string::npos){   //Ausgabe von find wenn nichts gefunden wird
                std::vector<std::string> vector = split(input, 'Q');    //split
                int teile = vector.size();
                for(int i = 0; i < teile; i++){
                    if(vector.at(i)=="Q") {     //nur Q soll rot sein
//                        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(handle, FOREGROUND_RED);
                        cout << "\x1B[40m\x1B[5m\x1B[31m" + vector.at(i);
                    } else {
//                        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
//                                                        FOREGROUND_BLUE);
                        cout << "\x1B[0m\x1B[40m\x1B[37m"+vector.at(i);
                    }
                }
                cout << endl;
            } else {
//                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
//                                                FOREGROUND_BLUE);
                std::cout << "\x1B[40m\x1B[37m"+input << std::endl;
            }
        }       //Datei schließen
        cout << "\x1B[0m" <<endl;
        inFile.close();
    } else {
        cout << "Datei kann nicht geoeffnet werden!";
    }

}

/**
 * Splittet einen String bei einem bestimmten char
 * @param eingabe
 * @param sucher
 * @return ausgabe
 */
vector<string> Artikeldialog::split(string eingabe, char sucher) {
    vector<string> ausgabe;
    stringstream ss(eingabe); //string zu stream
    string token;
    string s(1, sucher);

    while (getline(ss, token, sucher)) {
        ausgabe.push_back(token);
        ausgabe.push_back(s);
    }
    ausgabe.pop_back(); //letzer string zu viel, deshalb muss es weg

    return ausgabe;
}