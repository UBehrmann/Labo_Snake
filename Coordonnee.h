// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Terrain.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_COORDONNEE_H
#define SURVIVOR_COORDONNEE_H


class Coordonnee {
public:

    Coordonnee() : x(0), y(0) {};

    Coordonnee(int x, int y);

    int getX() const;

    int getY() const;

    void operator+=(const Coordonnee c);

private:
    int x;
    int y;
};

#endif //SURVIVOR_COORDONNEE_H
