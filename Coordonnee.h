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

    Coordonnee() : x(0), y(0), r(255), g(255), b(255) {};

    Coordonnee(int x, int y, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255);

    void setCouleur(unsigned char r, unsigned char g, unsigned char b);

    int getX() const;

    int getY() const;

    unsigned char getR() const;

    unsigned char getG() const;

    unsigned char getB() const;

    void operator+=(const Coordonnee c);

    bool operator!=(const Coordonnee c);

    bool operator==(const Coordonnee c);

    bool memePos(Coordonnee coordonne);

private:
    // Position
    int x;
    int y;

    // Couleurs
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif //SURVIVOR_COORDONNEE_H
