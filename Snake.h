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
#include "Coordonnee.h"

#include <array>
#include <vector>


/**
 * Les déplacements relatifs autorisé de la tondeuse
 */
const std::vector<Coordonnee> DEPLACEMENTS_AUTORISE = {
        {0, -1}, // Haut
        {1, 0},  // Droite
        {0, 1},  // Bas
        {-1, 0}  // Gauche
};

using Corps = std::vector<Coordonnee>;

class Snake {
public:

    Snake(); // Besoin pour initialiser le vecteur de Snake

    Snake(Coordonnee position);

    void initTailleFenetre(int largeurFenetre, int longeurFenetre);

    void creationPomme();

    void bouge();

    const Coordonnee &getTete() const;

    const Corps &getCorps() const;

    const Coordonnee &getPomme() const;

private:
    Coordonnee tete;
    Corps corps;
    Coordonnee posPomme;
    int valPomme;

    static const int largeurFenetre;
    static const int longeurFenetre;
};


#endif //LABO_SNAKE_SNAKE_H
