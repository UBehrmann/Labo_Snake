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

int Snake::longeurFenetre = 100;
int Snake::largeurFenetre = 80;

Snake::Snake() {
}

Snake::Snake(Coordonnee position){
    // Définir toutes les parties du corps à la même position que la tête
    this->tete = position;

    this->corps.resize(10);
    for (size_t i = 0; i < 10; ++i) {       //Définir const taille Serpent au départ
        this->corps[i] = this->tete;
        this->corps[i].setCouleur(255,0,255);
    }

    creationPomme();
}

const Coordonnee &Snake::getTete() const {
    return tete;
}

const Corps &Snake::getCorps() const {
    return corps;
}

const Coordonnee &Snake::getPomme() const {
    return posPomme;
}

void Snake::creationPomme() {
//    this->posPomme = {, , }; //
    posPomme.setXY(nbAleatoire(0, largeurFenetre), nbAleatoire(0, longeurFenetre));
    posPomme.setCouleur(0, 255, 0);
    this->valPomme = nbAleatoire(1,10);
}

void Snake::bouge() {

    // Itérateur qui donne la prochaine case qui remplacera la tête
    std::vector<Coordonnee>::iterator iterateur = this->corps.begin() + 1;

    // Déplacement du corps (dernier pixel prend la place de la tête)
    *iterateur = this->tete;
    ++iterateur;

    // Si l'itérateur arrive au bout du corps revenir juste après la tête
    if (iterateur == this->corps.end()) {
        iterateur = this->corps.begin() + 1;
    }

    // Définition de la nouvelle position de la tête
    int distHorizontale = this->getPomme().getX() - this->tete.getX();
    int distVerticale   = this->getPomme().getY() - this->tete.getY();

    if (abs(distHorizontale) > abs(distVerticale)) {
        this->tete += DEPLACEMENTS_AUTORISE[distHorizontale < 0 ? 3 : 1];
    }
    else {
        this->tete += DEPLACEMENTS_AUTORISE[distVerticale < 0 ? 0 : 2];
    }
}

// https://stackoverflow.com/questions/583076/c-c-changing-the-value-of-a-const
void Snake::initTailleFenetre(int largeurFenetreRecu, int longeurFenetreRecu) {

    largeurFenetre = largeurFenetreRecu;
    longeurFenetre = longeurFenetreRecu;

}
