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

    ~Snake();

    static void initTailleFenetre(int largeurFenetre, int longeurFenetre);

    bool operator!=(const Snake s);

    void creationPomme();

    void bouge();

    Coordonnee getTete() const;

    const Corps &getCorps() const;

    Coordonnee &getPomme();

    const int getId() const;

    void setTete();

    void serpentEstMange(Coordonnee impacte);

    void serpentMange(size_t taille);

    void serpentEstMort();

private:
    Corps corps;
    Coordonnee tete;
    Coordonnee posPomme;
    const int ID;
    int valPomme;


    void mangePomme(Corps::iterator iterateur);

    void ajouteCorps(Corps::iterator iterateur, int taille);


};


#endif //LABO_SNAKE_SNAKE_H
