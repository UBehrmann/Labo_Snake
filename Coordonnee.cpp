//------------------------------------------------------------------------------
// Fichier      Coordonnee.cpp
// Auteur       Urs Behrmann et Calum Quinn
// Date         09.01.2023
//
// But          Class qui sert a stocker et transmettre des donnees de position et de couleur
//
// Remarque
//
// Modifs       n/a
//
// Compilateur  MinGW w64 9.0
//------------------------------------------------------------------------------

#include "Coordonnee.h"

Coordonnee::Coordonnee(int x, int y, unsigned char r, unsigned char g, unsigned char b) : x(x), y(y), r(r), g
(g), b(b) {}

void Coordonnee::operator+=(const Coordonnee c) {
    x += c.x;
    y += c.y;
}

Coordonnee& Coordonnee::operator=(const Coordonnee c) {
    x = c.x;
    y = c.y;
    return *this;
}

bool Coordonnee::operator!=(const Coordonnee c) const{
    return !(*this == c);
}

bool Coordonnee::operator==(const Coordonnee c) const{
    return x == c.x && y == c.y;
}

void Coordonnee::setCouleur(unsigned char _r, unsigned char _g, unsigned char _b) {
    this->r = _r;
    this->g = _g;
    this->b = _b;
}

int Coordonnee::getX() const {
    return x;
}

int Coordonnee::getY() const {
    return y;
}

unsigned char Coordonnee::getR() const {
    return r;
}

unsigned char Coordonnee::getG() const {
    return g;
}

unsigned char Coordonnee::getB() const {
    return b;
}

void Coordonnee::setXY(int _x, int _y) {
    this->x = _x;
    this->y = _y;
}
