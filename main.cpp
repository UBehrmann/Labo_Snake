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
#include "Pixel.h"

using namespace std;

int main (int argc, char* args[]) {

    vector<Pixel> snake;
    snake.push_back(Pixel(20, 20, 0, 0, 255));
    snake.push_back(Pixel(20, 21, 0, 0, 255));
    snake.push_back(Pixel(20, 22, 0, 0, 255));
    snake.push_back(Pixel(20, 23, 0, 0, 255));
    vector<Pixel> pomme;
    pomme.push_back(Pixel(30, 30, 255, 0, 0));


    Fenetre fenetre;

    while (fenetre.appIsRunning){
        fenetre.update(snake, pomme);
    }


    return EXIT_SUCCESS;
}