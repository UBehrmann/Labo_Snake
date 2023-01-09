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

void Fenetre::Affiche(const vector<Coordonnee>& serpants, const vector<Coordonnee>& pommes) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        switch (event.type) {
            case SDL_QUIT     :
                appIsRunning = false;
                break;
        }
    }

    // Clear
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Ajoute objects

//    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
//    SDL_RenderDrawPoint(renderer, point.x, point.y);


    // Render
    SDL_RenderPresent(renderer);
}

Fenetre::~Fenetre() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
