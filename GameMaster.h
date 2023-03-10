//------------------------------------------------------------------------------
// Fichier      GameMaster.h
// Auteur       Urs Behrmann et Calum Quinn
// Date         09.01.2023
//
// But          Class qui gere le deroulement du jeu : les actions des serpents et l'affichage du terrain de jeu.
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

    /**
     * @name                : GameMaster
     *
     * @but                 : Constructeur de la classe Snake
     *
     * @return              : void
     * @throws              : NIL
     */
    GameMaster();

    /**
     * @name                : init
     *
     * @but                 : Fonction qui initialise le terrain ainsi que les serpents
     *
     * @return              : void
     * @throws              : NIL
     */
    void init();

    /**
     * @name                : update
     *
     * @but                 : Fonction qui met à jour les serpents et l'affichage
     *
     * @return              : void
     * @throws              : NIL
     */
    void update();

    /**
     * @name                : appIsRunning
     *
     * @but                 : Fonction qui retourne si le jeu tourne encore
     *
     * @return              : Vrai, si le jeu tourne, sinon faux
     * @throws              : NIL
     */
    bool appIsRunning() const;

private:
    std::vector<Snake> serpents;

    Fenetre fenetre;

    /**
     * @name                : updateSerpents
     *
     * @but                 : Fonction qui met à jour les serpents
     *
     * @return              : void
     * @throws              : NIL
     */
    void updateSerpents();

    /**
     * @name                : affichage
     *
     * @but                 : Actualise l'affichage graphique du jeu
     *
     * @return              : void
     * @throws              : NIL
     */
    void affichage();

    /**
     * @name                : estOccupe
     *
     * @but                 : Verifie si la coordonnee est occupee ou non par un serpent
     *
     * @param coordonnee    : Coordonnee test
     * @return              : Vrai, si la coordonnee est occupee, sinon faux
     * @throws              : NIL
     */
    bool estOccupe(Coordonnee coordonnee);

    /**
     * @name 	            : serpentEstMort
     *
     * @but 	            : Retire le serpent qui vient de mourir
     * @param serpentMort   :
     * @return              : void
     * @throws              : NIL
     */
    void serpentEstMort(Snake& serpentMort, Snake& serpentTueur);

    /**
     * @name 	            : checkCollision
     *
     * @but 	            : Test si deux serpents sont entres en collision
     * @param serpent1	    : premier serpent
     * @param serpent2	    : deuxieme serpent
     * @return              : Vrai, s'il y a eu une collision, sinon faux
     * @throws              : NIL
     */
    static bool checkCollision(const Snake &serpent1, const Snake &serpent2);

    /**
     * @name 	            : gestionCollision
     *
     * @but 	            : gere la collision entre deux serpents
     * @param serpent1	    : premier serpent
     * @param serpent2	    : deuxieme serpent
     * @return              : void
     * @throws              : NIL
     */
    void gestionCollision(Snake &serpent1, Snake &serpent2);
};

#endif //LABO_SNAKE_GAMEMASTER_H
