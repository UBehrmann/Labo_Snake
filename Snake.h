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

#include <vector>   // Pour les vecteurs de coordonées


// Les déplacements relatifs autorisé du serpent
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

    static int largeurFenetre;
    static int longeurFenetre;
    const int tailleSerpent = 10;

    // Constructeur par défaut pour initialiser le vecteur contenant les serpents
    Snake();

    // Constructeur
    Snake(Coordonnee position, int id);

    // Destructeur
    ~Snake();

    // Fonction qui initialise la fenêtre pour les serpents
    // Paramètres
    //  largeurFenetre      : Largeur de la fenêtre
    //  longeurFenetre      : Longeur de la fenêtre
    static void initTailleFenetre(int largeurFenetre, int longeurFenetre);

    // Fonction qui défini l'opérateur != entre deux serpents
    // Paramètres
    //  s                   : serpent
    bool operator!=(const Snake& s) const;

    // Fonction qui défini l'opérateur = entre deux serpents
    // Paramètres
    //  s                   : serpent
    Snake& operator=(const Snake& s);

    // Fonction qui crée une nouvelle pomme pour un serpent
    void creationPomme();

    // Fonction qui déplace le serpent
    void bouge();

    // Fonction qui retourne la position de la tête
    Coordonnee getTete() const;

    // Fonction qui retourne le vecteur du corps
    const Corps &getCorps() const;

    // Fonction qui retourne la position de la pomme
    Coordonnee &getPomme();

    // Fonction qui retourne l'identificateur du serpent
    int getId() const;

    // Fonction qui affecte une position à la tête
    void setTete();

    // Fonction qui retire des parties de corps à un serpent mordu
    // Paramètres
    //  impacte     : coordonée de la morçure
    void serpentEstMange(Coordonnee impacte);

    // Fonction qui ajoute des parties de corps à un serpent qui a mordu
    // Paramètres
    //  taille      : quantité de parties à ajouter
    void serpentMange(int taille);

    // Fonction qui détruit un serpent mort
    void serpentEstMort();

private:
    Corps corps;
    Coordonnee tete;
    Coordonnee posPomme;
    int ID;
    int valPomme;

    // Fonction qui fait grandir le serpent et replace une nouvelle pomme
    // Paramètres
    // iterateur    : position où ajouter les parties
    void mangePomme(Corps::iterator iterateur);

    // Fonction qui augmente la taille du serpent
    // Paramètres
    //  iterateur   : position où ajouter les parties
    //  taille      : quantité de parties à ajouter
    void ajouteCorps(Corps::iterator iterateur, int taille);

};

#endif //LABO_SNAKE_SNAKE_H