//------------------------------------------------------------------------------
// Fichier      Fenetre.cpp
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

#include "Fenetre.h"

using namespace std;

Fenetre::Fenetre() {}

Fenetre::~Fenetre() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Fenetre::update(const vector<Coordonnee>& objets) {

    pollEvent();

    clear();

    addObjects(objets);

    SDL_RenderPresent(renderer);
}

void Fenetre::pollEvent(){

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        switch (event.type) {
            case SDL_QUIT     :
                appIsRunning = false;
                break;
        }
    }
}

void Fenetre::clear(){
    // Clear
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void Fenetre::addObjects(const vector<Coordonnee> &objets) {
    for (Coordonnee objet : objets) {
        SDL_SetRenderDrawColor(renderer, objet.getR() , objet.getG(), objet.getB(), SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(renderer, objet.getX(), objet.getY());
    }
}

void Fenetre::initFenetre(int largeurFenetre, int longeurFenetre, float scale) {

    this->largeurFenetre = largeurFenetre;
    this->longeurFenetre = longeurFenetre;
    this->scale = scale;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(largeurFenetre  * (int)scale,
                                longeurFenetre * (int)scale,
                                SDL_WINDOW_SHOWN,
                                &window, &renderer);

    if (window == nullptr or renderer == nullptr) {
        cout << "SDL not ready ... quitting" << endl;
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(window, "SDL Demo / Moving points");
    SDL_RenderSetScale(renderer, scale, scale);
}
