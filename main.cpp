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

#include "GameMaster.h"

#include <cstdlib>  // Pour EXIT_SUCCESS

using namespace std;

int main (int argc, char* args[]) {

    // Déclare un jeu
    GameMaster gm;

    // Initialise une fenêtre et les serpents
    gm.init();

    // Boucle les étapes de déplacement et afficage tant que le jeu tourne
    while (gm.appIsRunning()){
        gm.update();
    }

    return EXIT_SUCCESS;
}