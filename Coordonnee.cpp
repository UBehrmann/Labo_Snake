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

Coordonnee::Coordonnee(int x, int y, unsigned char r, unsigned char g, unsigned char b) : x(x), y(y), r(r), g
(g), b(b) {}

Coordonnee& Coordonnee::operator+=(const Coordonnee c) {
    x += c.x;
    y += c.y;
}

Coordonnee& Coordonnee::operator=(const Coordonnee c) {
    x = c.x;
    y = c.y;
}

bool Coordonnee::operator!=(const Coordonnee c){
    return !(*this == c);
}

bool Coordonnee::operator==(const Coordonnee c){
    return x == c.x && y == c.y;
}

void Coordonnee::setCouleur(unsigned char r, unsigned char g, unsigned char b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Coordonnee::memePos(Coordonnee coordonnee) {
    return *this == coordonnee;
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

void Coordonnee::setX(int x) {
    Coordonnee::x = x;
}

void Coordonnee::setY(int y) {
    Coordonnee::y = y;
}

void Coordonnee::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}
