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

    void update(const std::vector<Coordonnee>& serpants, const std::vector<Coordonnee>& pommes);

    virtual ~Fenetre();

    bool           appIsRunning   = true;

private:
    SDL_Window*    window         = nullptr;
    SDL_Renderer*  renderer       = nullptr;



    const int      WINDOW_WIDTH   = 80;
    const int      WINDOW_HEIGTH  = 50;
    const int      SCALE          = 10;

    void pollEvent();

    void clear();

    void addObjects(const std::vector<Coordonnee> &serpants, const std::vector<Coordonnee> &pommes);
};


#endif //LABO_SNAKE_FENETRE_H
