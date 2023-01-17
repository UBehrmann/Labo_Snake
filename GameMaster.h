//------------------------------------------------------------------------------
// Fichier      GameMaster.h
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

#ifndef LABO_SNAKE_GAMEMASTER_H
#define LABO_SNAKE_GAMEMASTER_H

#include "Fenetre.h"
#include "Snake.h"

#include <vector>   // Pour les vecteurs de coordonées

class GameMaster {
public:
    // Constructeur
    GameMaster();

    // Fonction qui initialise le terrain ainsi que les serpents
    // Paramètres
    void init();

    // Fonction qui mets à jour les serpents et l'affichage
    void update();

    // Fonction qui retourne si le jeu tourne encore
    bool appIsRunning() const;

    // Fonction qui retourne si une coordonée est déjà prise
    // Paramètres
    // c        : coordonée à vérifier
    bool estOccupe(Coordonnee c);


private:
    std::vector<Snake> serpents;

    Fenetre fenetre;

    // Fonction qui met à jour les serpents
    void updateSerpents();

    // Fonction qui met à jour l'affichage
    void affichage();
};


#endif //LABO_SNAKE_GAMEMASTER_H
