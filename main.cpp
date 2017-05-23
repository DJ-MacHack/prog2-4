#include "Lagerdialog.h"

/**
* @file: main.cpp
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

int main() {
    try {
        Lagerdialog lagerdialog;
        lagerdialog.start();
    } catch (const string& e) {
        cout << "Main: " << e << endl;
    }
    catch (exception e){
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "Unbekannter Fehler!" << endl;
    }
}