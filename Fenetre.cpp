//------------------------------------------------------------------------------
// Fichier      Fenetre.cpp
// Auteur       Urs Behrmann et Calum Quinn
// Date         09.01.2023
//
// But          Class qui gere l'affichage du terrain de jeu avec les serpents et pommes qui sont envoyé du GameMaster
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

Fenetre::Fenetre() = default;

Fenetre::~Fenetre() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Fenetre::update(const vector<Coordonnee>& objets) {

    // Contrôle si l'utilisateur ferme la fenêtre
    sondeEvenement();

    // Vide l'affichage précédent
    videAffichage();

    // Ajoute les éléments du prochain affichage
    ajouteElements(objets);

    // Affiche les éléments
    SDL_RenderPresent(renderer);
}

void Fenetre::sondeEvenement(){
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

void Fenetre::videAffichage(){
    // Vide l'affichage précédent
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void Fenetre::ajouteElements(const vector<Coordonnee> &objets) {
    // Met tous les éléments à afficher dans une variable d'affichage
    for (Coordonnee objet : objets) {
        SDL_SetRenderDrawColor(renderer, objet.getR() , objet.getG(), objet.getB(), SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(renderer, objet.getX(), objet.getY());
    }
}

void Fenetre::initFenetre(int _largeurFenetre, int _longeurFenetre, float _scale) {
    // Initialise la taille de la fenêtre
    this->largeurFenetre = _largeurFenetre;
    this->longeurFenetre = _longeurFenetre;
    this->scale = _scale;

    SDL_Init(SDL_INIT_VIDEO);

    // Crée la fenêtre
    SDL_CreateWindowAndRenderer(this->largeurFenetre  * (int)this->scale,
                                this->longeurFenetre * (int)this->scale,
                                SDL_WINDOW_SHOWN,
                                &window, &renderer);

    // Ferme la fenêtre en cas de problème d'initialisation de SDL
    if (window == nullptr or renderer == nullptr) {
        cout << "SDL not ready ... quitting" << endl;
        exit(EXIT_FAILURE);
    }

    // Met un titre à la fenêtre et agrandi les pixels
    SDL_SetWindowTitle(window, "Labo_Snake");
    SDL_RenderSetScale(renderer, scale, scale);
}
