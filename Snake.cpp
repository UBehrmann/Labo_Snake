//------------------------------------------------------------------------------
// Fichier      Snake.cpp
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

#include "Snake.h"
#include "Annexe.h"

#include <cmath>
#include <iostream>

int Snake::longeurFenetre = 100;
int Snake::largeurFenetre = 80;

Snake::Snake() : ID(-1){
}

Snake::Snake(Coordonnee position, int id) : ID(id){

    // Assigne la position aléatoire à la tête
    tete = position;
    tete.setCouleur(0,0,0);

    // Définir toutes les parties du corps à la même position que la tête
    for (size_t i = 0; i < 10; ++i) {       //Définir const taille Serpent au départ
        corps.push_back(tete);
        corps[i].setCouleur(0,0,0);
    }

    iterateur = corps.begin() + 1;

    creationPomme();
}

Coordonnee Snake::getTete() const{
    return tete;
}

const Corps &Snake::getCorps() const {
    return corps;
}

const Coordonnee &Snake::getPomme() const {
    return posPomme;
}

bool Snake::operator!=(const Snake s) {
    return this->ID != s.ID;

}


void Snake::creationPomme() {
//    this->posPomme = {, , }; //
    posPomme.setXY(nbAleatoire(0, largeurFenetre), nbAleatoire(0, longeurFenetre));
    posPomme.setCouleur(0, 255, 0);
    valPomme = nbAleatoire(1,10);
}

void Snake::bouge() {


    // Déplacement du corps (dernier pixel prend la place de la tête)
    *iterateur = tete;
    ++iterateur;

    // Si l'itérateur arrive au bout du corps revenir juste après la tête
    if (iterateur == corps.end()) {
        iterateur = corps.begin() + 1;
    }

    // Définition de la nouvelle position de la tête
    int distHorizontale = posPomme.getX() - tete.getX();
    int distVerticale   = posPomme.getY() - tete.getY();

    if (abs(distHorizontale) > abs(distVerticale)) {
        tete += DEPLACEMENTS_AUTORISE[distHorizontale < 0 ? 3 : 1];
    }
    else {
        tete += DEPLACEMENTS_AUTORISE[distVerticale < 0 ? 0 : 2];
    }
    corps.at(0) = tete;

    // Controle si il a atteint la pomme
    if (tete == posPomme) {
        creationPomme();
    }
}

void mangeSerpent(Snake s, size_t k) {
   // s.getCorps().erase(s.getCorps().begin() + k, s.getCorps().end());
}


// https://stackoverflow.com/questions/583076/c-c-changing-the-value-of-a-const
void Snake::initTailleFenetre(int largeurFenetreRecu, int longeurFenetreRecu) {

    largeurFenetre = largeurFenetreRecu;
    longeurFenetre = longeurFenetreRecu;

}