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

    static int largeurFenetre;
    static int longeurFenetre;

    Snake(); // Besoin pour initialiser le vecteur de Snake

    Snake(Coordonnee position, int id);

    static void initTailleFenetre(int largeurFenetre, int longeurFenetre);

    bool operator!=(const Snake s);

    void creationPomme();

    void bouge();

    static void mangeSerpent(Snake s, size_t k);

    Coordonnee getTete() const;

    const Corps &getCorps() const;

    Coordonnee &getPomme();

    void setTete();

private:
    Corps corps;
    Coordonnee tete;
    Coordonnee posPomme;
    const int ID;
    int valPomme;
    // Itérateur qui donne la prochaine case qui remplacera la tête
    Corps::iterator iterateur;

    void mangePomme();
};


#endif //LABO_SNAKE_SNAKE_H
