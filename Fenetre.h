//------------------------------------------------------------------------------
// Fichier      Fenetre.h
// Auteur       Urs Behrmann et Calum Quinn
// Date         09.01.2023
//
// But          Class qui gere l'affichage du terrain de jeu avec les serpents et pommes qui sont envoyé du GameMaster
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
    /**
     * @name                : Fenetre
     *
     * @but                 : Constructeur par défaut
     *
     * @return              : void
     * @throws              : NIL
     */
    Fenetre();

    /**
     * @name                : ~Fenetre
     *
     * @but                 : Destructeur
     *
     * @return              : void
     * @throws              : NIL
     */
    virtual ~Fenetre();

    /**
     * @name                    : initFenetre
     *
     * @but                     : Fonction qui initialise la fenêtre
     *
     * @param largeurFenetre    : Largeur de la fenêtre
     * @param longeurFenetre    : Longeur de la fenêtre
     * @param scale             : Echelle auquel augmenter la taille d'un pixel
     * @return                  : void
     * @throws                  : NIL
     */
    void initFenetre(int largeurFenetre, int longeurFenetre, float scale = 10);

    /**
     * @name            : initFenetre
     *
     * @but             : Fonction qui met à jour l'affichage
     *
     * @param objects   : vecteur de coordonées à afficher
     * @return          : void
     * @throws          : NIL
     */
    void update(const std::vector<Coordonnee>& objets);

    bool appIsRunning = true;

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int largeurFenetre = 100;
    int longeurFenetre = 80;
    float scale = 10;

    // Fonction prive

    /**
     * @name            : sondeEvenement
     *
     * @but             : Fonction qui contrôle si l'utilisateur quitte la fenêtre
     *
     * @return          : void
     * @throws          : NIL
     */
    void sondeEvenement();

    /**
     * @name            : sondeEvenement
     *
     * @but             : Fonction qui vide l'affichage
     *
     * @return          : void
     * @throws          : NIL
     */
    void videAffichage();

    /**
     * @name            : ajouteElements
     *
     * @but             : Fonction qui ajoute les éléments à afficher
     *
     * @param objets   : vecteur de coordonees à afficher
     * @return          : void
     * @throws          : NIL
     */
    void ajouteElements(const std::vector<Coordonnee>& objets);
};

#endif //LABO_SNAKE_FENETRE_H