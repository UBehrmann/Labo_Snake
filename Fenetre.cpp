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
#include "Fenetre.h"

#include <iostream> // Pour les cout

using namespace std;

Fenetre::Fenetre() {}

Fenetre::~Fenetre() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Fenetre::update(const vector<Coordonnee>& objets) {

    // Contrôle si l'utilisateur ferme la fenêtre
    pollEvent();

    // Vide l'affichage précédent
    clear();

    // Ajoute les éléments du prochain affichage
    addObjects(objets);

    // Affiche les éléments
    SDL_RenderPresent(renderer);
}

void Fenetre::pollEvent(){
    // Quitte le programme si l'utilisateur ferme la fenêtre
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
    // Vide l'affichage précédent
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void Fenetre::addObjects(const vector<Coordonnee> &objets) {
    // Mets tous les éléments à afficher dans une variable d'affichage
    for (Coordonnee objet : objets) {
        SDL_SetRenderDrawColor(renderer, objet.getR() , objet.getG(), objet.getB(), SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(renderer, objet.getX(), objet.getY());
    }
}

void Fenetre::initFenetre(int largeurFenetre, int longeurFenetre, float scale) {
    // Initialise la taille de la fenêtre
    this->largeurFenetre = largeurFenetre;
    this->longeurFenetre = longeurFenetre;
    this->scale = scale;

    SDL_Init(SDL_INIT_VIDEO);

    // Crée la fenêtre
    SDL_CreateWindowAndRenderer(this->largeurFenetre  * (int)this->scale,
                                this->longeurFenetre * (int)this->scale,
                                SDL_WINDOW_SHOWN,
                                &window, &renderer);

    // Ferme la fenêtre en cas de problême d'initialisation de SDL
    if (window == nullptr or renderer == nullptr) {
        cout << "SDL not ready ... quitting" << endl;
        exit(EXIT_FAILURE);
    }

    // Met un titre à la fenêtre et agrandi les pixels
    SDL_SetWindowTitle(window, "Labo_Snake");
    SDL_RenderSetScale(renderer, scale, scale);
}
