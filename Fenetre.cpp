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

Fenetre::Fenetre() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH  * SCALE,
                                WINDOW_HEIGTH * SCALE,
                                SDL_WINDOW_SHOWN,
                                &window, &renderer);
    if (window == nullptr or renderer == nullptr) {
        cout << "SDL not ready ... quitting" << endl;
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(window, "SDL Demo / Moving points");
    SDL_RenderSetScale(renderer, SCALE, SCALE);
}

Fenetre::~Fenetre() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Fenetre::update(const vector<Coordonnee> &serpants, const vector<Coordonnee> &pommes) {

    pollEvent();

    clear();

    addObjects(serpants, pommes);

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

void Fenetre::addObjects(const vector<Coordonnee> &serpants, const vector<Coordonnee> &pommes){

    // Ajoute objects

    // TODO : methodes d'ajout d'objets vector<Coordonnee>

    for (Coordonnee serpant : serpants) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(renderer, serpant.getX(), serpant.getY());
    }

    for ( Coordonnee pomme : pommes){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(renderer, pomme.getX(), pomme.getY());
    }
}
