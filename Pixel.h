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


class Pixel {
public:

    Pixel() : x(0), y(0), r(255), g(255), b(255) {};

    Pixel(int x, int y, int r = 255, int g = 255, int b = 255);

    void setCouleur(int r, int g, int b);

    int getX() const;

    int getY() const;

    int getR() const;

    int getG() const;

    int getB() const;

    void operator+=(const Pixel c);

private:
    // Position
    int x;
    int y;

    // Couleurs
    int r;
    int g;
    int b;
};

#endif //SURVIVOR_COORDONNEE_H
