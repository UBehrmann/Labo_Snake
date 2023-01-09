// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Terrain.cpp
// Auteur(s)      : Calum Quinn et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include "Coordonnee.h"

int Coordonnee::getX() const {
    return x;
}

int Coordonnee::getY() const {
    return y;
}

Coordonnee::Coordonnee(int x, int y) : x(x), y(y) {}

void Coordonnee::operator+=(const Coordonnee c) {
    x += c.x;
    y += c.y;
}
