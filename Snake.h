//------------------------------------------------------------------------------
// Fichier      Snake.h
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

#ifndef LABO_SNAKE_SNAKE_H
#define LABO_SNAKE_SNAKE_H

#include "Annexe.h"

#include <array>
#include <vector>

using Coordonee = std::array<int, 2>;
using Corps = std::vector<std::array<int, 2>>;

class Snake {
public:
    Snake(const int longeur, const int largeur) {
        tete[0] = nbAleatoire(0,largeur);
        tete[0] = nbAleatoire(0,longeur);
    }
private:
    Coordonee tete;
    Corps corps;
};


#endif //LABO_SNAKE_SNAKE_H
