//------------------------------------------------------------------------------
// Fichier      GameMaster.cpp
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

#include "GameMaster.h"
#include "Annexe.h"
#include "Coordonnee.h"

#include <iostream>

GameMaster::GameMaster() {

}

void GameMaster:: init() {
    // Saisies
    int longeurFenetre = 100; // saisie("Longeur fenetre", "Longeur fenetre", 80, 200);
    int largeurFenetre = 80; // saisie("", "Largeur fenetre", 80, 200);
    size_t nbreSerpents = 20; // (size_t)saisie("", "Nbre de serpents", 5, 20);

    // Init fenêtre
    fenetre.initFenetre(longeurFenetre, largeurFenetre);

    // Init serpents

    Snake::initTailleFenetre(largeurFenetre, longeurFenetre);

    // Remplir vecteur de serpents en contrôlant de ne pas en avoir au même endroit
    Coordonnee position;
    for (size_t i = 0; i < nbreSerpents; ++i) {
        do {
            position = {nbAleatoire(0,largeurFenetre), nbAleatoire(0,longeurFenetre)};
        } while (estOccupe(position));

        serpents.push_back(Snake(position, i));
    }
}


void GameMaster::update() {
    pixels.clear();

    // Update serpents et controle s'ils mangent des autres
    for (Snake i : serpents) {
        i.bouge();
        for (Snake j : serpents) {
            if (j != i) {
                for (size_t k = 0; k < j.getCorps().size(); ++k) {
                    if (i.getTete() == j.getCorps()[k]) {
                        //Snake::mangeSerpent(j,k);
                    }
                }
            }
        }
    }

    // Update Affichage

    // Ajoute tous les corps des serpents et les pommes a un vecteur de pixels
    for (const Snake& serpent : serpents) {
        pixels.insert(pixels.end(), serpent.getCorps().begin(), serpent.getCorps().end());
        pixels.push_back(serpent.getPomme());
    }

    fenetre.update(pixels);
}

bool GameMaster::appIsRunning() const {
    return fenetre.appIsRunning;
}

bool GameMaster::estOccupe(Coordonnee c) {
    for ( const Snake& s : serpents)
        if ( s.getTete() == c )
            return true;

    return false;
}


