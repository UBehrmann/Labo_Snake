//------------------------------------------------------------------------------
// Fichier      Fenetre.h
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

#ifndef LABO_SNAKE_FENETRE_H
#define LABO_SNAKE_FENETRE_H

#include "Coordonnee.h"

#include <sdl.h>    // Pour ajouter la librairie graphique
#include <vector>   // Pour les vecteurs de coordonées

class Fenetre {
public:
    // Constructeur par défaut
    Fenetre();

    // Destructeur
    virtual ~Fenetre();

    // Fonction qui initialise la fenêtre
    // Paramètres
    //  largeurFenetre      : Largeur de la fenêtre
    //  longeurFenetre      : Longeur de la fenêtre
    //  scale               : Echelle auquel augmenter la taille d'un pixel
    void initFenetre(int largeurFenetre, int longeurFenetre, float scale = 10);

    // Fonction qui met à jour l'affichage
    // Paramètres
    //  objects      : vecteur de coordonées à afficher
    void update(const std::vector<Coordonnee>& objets);

    bool appIsRunning = true;

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int largeurFenetre;
    int longeurFenetre;
    float scale;

    // Fonction qui contrôle si l'utilisateur quitte la fenêtre
    void pollEvent();

    // Fonction qui vide l'affichage
    void clear();

    // Fonction qui ajoute les éléments à afficher
    // Paramètres
    //  objects      : vecteur de coordonées à afficher
    void addObjects(const std::vector<Coordonnee>& objets);
};

#endif //LABO_SNAKE_FENETRE_H