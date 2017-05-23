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
    Lager lager = newLager();
    this->lager = &lager;
}

Lager newLager(){
    string name;
    int dimensionen;
    cout << "Name fuer das neue Lager: ";
    cin >> name;
    cout << endl;
    cout << "Dimensionen fuer das neue Lager: ";
    cin >> dimensionen;
    cout << endl;
    Lager lager(name, dimensionen);
    return lager;
}

void start(){

}

string Lagerdialog::toString() const {
    ostringstream o;
    //o << "Lager: " << name << '\n';
   // for (int i = 0; i < this->lager.getDimension(); i++) { o << kontoTab[i]->toString() << '\n'; } o << endl;
    return o.str(); }