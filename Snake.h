//------------------------------------------------------------------------------
// Fichier      Snake.h
// Auteur       Urs Behrmann et Calum Quinn
// Date         09.01.2023
//
// But          Class qui contient les donnees pour representer un serpent dans le terrain de jeu et des fonctions
//              pour les differents evenements qui peuvent lui etre apliques
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

#include <vector>   // Pour les vecteurs de coordonées

// Les déplacements relatifs autorisés du serpent
const std::vector<Coordonnee> DEPLACEMENTS_AUTORISE = {
        {0, -1}, // Haut
        {1, 0},  // Droite
        {0, 1},  // Bas
        {-1, 0}  // Gauche
};

// Défini un type Corps pour faciliter l'écriture
using Corps = std::vector<Coordonnee>;

class Snake {
public:

    // Variables static
    static int largeurFenetre;
    static int longeurFenetre;

    /**
     * @name 	            : Snake
     *
     * @but 	            : Constructeur par défaut pour initialiser le vecteur contenant les serpents
     * @return              : void
     * @throws              : NIL
     */
    Snake();

    /**
     * @name 	            : Snake
     *
     * @but 	            : Constructeur par défaut pour initialiser le vecteur contenant les serpents
     * @param position	    : Position initial du serpent
     * @param id	        : ID du serpent
     * @return              : void
     * @throws              : NIL
     */
    Snake(Coordonnee position, int id);

    /**
     * @name 	            : ~Snake
     *
     * @but 	            : Destructeur de Snake
     * @return              : void
     * @throws              : NIL
     */
    ~Snake();

    /**
     * @name 	                : initTailleFenetre
     *
     * @but 	                : Fonction qui initialise la fenêtre pour les serpents
     * @param largeurFenetre    : Largeur de la fenêtre
     * @param longeurFenetre    : Longeur de la fenêtre
     * @return                  : void
     * @throws                  : NIL
     */
    static void initTailleFenetre(int largeurFenetre, int longeurFenetre);

    /**
     * @name 	    : operator==
     *
     * @but 	    : Fonction qui défini l'opérateur == entre deux serpents
     * @param s     : serpent
     * @return      : Vrai, si les deux serpents ont le même ID sinon faux
     * @throws      : NIL
     */
    bool operator==(const Snake& s) const;

    /**
     * @name 	    : operator!=
     *
     * @but 	    : Fonction qui défini l'opérateur != entre deux serpents
     * @param s     : serpent
     * @return      : Vrai, si les deux serpents n'ont pas le même ID sinon faux
     * @throws      : NIL
     */
    bool operator!=(const Snake& s) const;

    /**
     * @name 	    : operator=
     *
     * @but 	    : Fonction qui défini l'opérateur = entre deux serpents
     * @param s     : serpent
     * @return      : Le nouveau serpent qui a ete affecte par le serpent "s"
     * @throws      : NIL
     */
    Snake& operator=(const Snake& s);

    /**
     * @name 	    : bouge
     *
     * @but 	    : Fonction qui déplace le serpent
     * @return      : void
     * @throws      : NIL
     */
    void bouge();

    /**
     * @name 	    : getTete
     *
     * @but 	    : Fonction qui retourne la position de la tête
     * @return      : Un object de type Coordonnee qui est la position de la tete
     * @throws      : NIL
     */
    Coordonnee getTete() const;

    /**
     * @name 	    : getCorps
     *
     * @but 	    : Fonction qui retourne le vecteur du corps
     * @return      : Un objet de type vector<Coordonnee> qui represente le corps du serpent
     * @throws      : NIL
     */
    const Corps &getCorps() const;

    /**
     * @name 	    : getPomme
     *
     * @but 	    : Fonction qui retourne la position de la pomme
     * @return      : Un object de type Coordonnee qui represente la pomme de ce serpent
     * @throws      : NIL
     */
    Coordonnee &getPomme();

    /**
     * @name 	        : serpentEstMange
     *
     * @but 	        : Fonction qui retire des parties de corps à un serpent mordu
     * @param impacte   : coordonée de la morçure
     * @return          : void
     * @throws          : NIL
     */
    void serpentEstMange(Coordonnee impacte);

    /**
     * @name 	        : serpentMange
     *
     * @but 	        : Fonction qui ajoute des parties de corps à un serpent qui a mordu
     * @param taille    : quantité de parties à ajouter
     * @return          : void
     * @throws          : NIL
     */
    void serpentMange(int taille);

    /**
     * @name 	    : serpentEstMort
     *
     * @but 	    : Fonction qui détruit un serpent mort
     * @param tueur : Serpent qui a tué ce serpent
     * @return      : void
     * @throws      : NIL
     */
    void serpentEstMort(Snake& tueur);

private:
    // Variables de Snake
    Corps corps;
    Coordonnee tete;
    Coordonnee posPomme;
    int ID;
    int valPomme;
    const int tailleSerpent = 10;

    // Fonctions prive

    /**
     * @name 	        : mangePomme
     *
     * @but 	        : Fonction qui fait grandir le serpent et replace une nouvelle pomme
     * @param iterateur : position où ajouter les parties
     * @return          : void
     * @throws          : NIL
     */
    void mangePomme(Corps::iterator iterateur);

    /**
     * @name 	        : ajouteCorps
     *
     * @but 	        : Fonction qui augmente la taille du serpent
     * @param iterateur : position où ajouter les parties
     * @param taille    : quantité de parties à ajouter
     * @return          : void
     * @throws          : NIL
     */
    void ajouteCorps(Corps::iterator iterateur, int taille);

    /**
     * @name 	    : creationPomme
     *
     * @but 	    : Fonction qui crée une nouvelle pomme pour un serpent
     * @return      : void
     * @throws      : NIL
     */
    void creationPomme();
};

#endif //LABO_SNAKE_SNAKE_H