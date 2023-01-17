//------------------------------------------------------------------------------
// Fichier      Coordonnee.cpp
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

#include "Coordonnee.h"

int Coordonnee::getX() const {
    return x;
}

int Coordonnee::getY() const {
    return y;
}

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
    this->x = x;
}

void Coordonnee::setY(int y) {
    this->y = y;
}

void Coordonnee::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}
