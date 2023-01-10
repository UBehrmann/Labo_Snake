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

Coordonnee::Coordonnee(int x, int y, int r, int g, int b) : x(x), y(y), r(r), g
(g), b(b) {}

void Coordonnee::operator+=(const Coordonnee c) {
    x += c.x;
    y += c.y;
}

void Coordonnee::setCouleur(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

int Coordonnee::getR() const {
    return r;
}

int Coordonnee::getG() const {
    return g;
}

int Coordonnee::getB() const {
    return b;
}
