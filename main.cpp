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
#include "Fenetre.h"
#include "Snake.h"
#include <vector>
#include "Coordonnee.h"

using namespace std;

int main (int argc, char* args[]) {

    vector<Coordonnee> snake;
    snake.push_back(Coordonnee(20, 20, 0, 0, 255));
    snake.push_back(Coordonnee(20, 21, 0, 0, 255));
    snake.push_back(Coordonnee(20, 22, 0, 0, 255));
    snake.push_back(Coordonnee(20, 23, 0, 0, 255));
    vector<Coordonnee> pomme;
    pomme.push_back(Coordonnee(30, 30, 255, 0, 0));


    Fenetre fenetre;

    while (fenetre.appIsRunning){
        fenetre.update(snake, pomme);
    }


    return EXIT_SUCCESS;
}