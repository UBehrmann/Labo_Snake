// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Terrain.cpp
// Auteur(s)      : Calum Quinn et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include "Pixel.h"

int Pixel::getX() const {
    return x;
}

int Pixel::getY() const {
    return y;
}

Pixel::Pixel(int x, int y, int r, int g, int b) : x(x), y(y), r(r), g
(g), b(b) {}

void Pixel::operator+=(const Pixel c) {
    x += c.x;
    y += c.y;
}

void Pixel::setCouleur(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

int Pixel::getR() const {
    return r;
}

int Pixel::getG() const {
    return g;
}

int Pixel::getB() const {
    return b;
}
