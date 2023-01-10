//------------------------------------------------------------------------------
// Fichier      Fenetre.h
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

#ifndef LABO_SNAKE_FENETRE_H
#define LABO_SNAKE_FENETRE_H

#include <sdl.h>
#include <vector>
#include "Coordonnee.h"

class Fenetre {
public:
    Fenetre();

    void initFenetre(int largeurFenetre, int longeurFenetre, float scale = 10);

    void update(const std::vector<Coordonnee> &objets);

    virtual ~Fenetre();

    bool appIsRunning = true;

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int largeurFenetre;
    int longeurFenetre;
    float scale;

    void pollEvent();

    void clear();

    void addObjects(const std::vector<Coordonnee> &objets);
};


#endif //LABO_SNAKE_FENETRE_H
