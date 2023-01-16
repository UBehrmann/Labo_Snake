//------------------------------------------------------------------------------
// Fichier      main.cpp
// Auteur       Urs Behrmann et Calum Quinn
// Date         09.01.2023
//
// But
//
// Remarque
//
// Modifs       n/a
//
// Compilateur  MinGW w64 9.0
//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include "GameMaster.h"


using namespace std;

int main (int argc, char* args[]) {

    cout << "Fonctionne?";

    GameMaster gm;

    gm.init();

    while (gm.appIsRunning()){
        gm.update();
    }


    return EXIT_SUCCESS;
}