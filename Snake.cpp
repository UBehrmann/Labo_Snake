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

Snake:: Snake(Coordonnee position, int id) : ID(id){

    corps.reserve(200);

    // Assigne la position aléatoire à la tête
    tete = position;
    tete.setCouleur(0,0,0);

    // Définir toutes les parties du corps à la même position que la tête
    for (size_t i = 0; i < 10; ++i) {       //Définir const taille Serpent au départ
        corps.push_back(position);
        corps[i].setCouleur(0,0,0);
    }

    creationPomme();
}

Coordonnee Snake::getTete() const{
    return tete;
}

const Corps &Snake::getCorps() const {
    return this->corps;
}

Coordonnee &Snake::getPomme() {
    return posPomme;
}

bool Snake::operator!=(const Snake s) {
    return this->ID != s.ID;

}


void Snake::creationPomme() {
//    this->posPomme = {, , }; //
    posPomme.setXY(nbAleatoire(0, largeurFenetre), nbAleatoire(0, longeurFenetre));
    posPomme.setCouleur(0, 255, 0);
    valPomme = nbAleatoire(2,10);
}

void Snake::bouge() {



    // Déplacement du corps (dernier pixel prend la place de la tête)

    // Itérateur qui donne la prochaine case qui remplacera la tête
    Corps::iterator iterateur = std::find(corps.begin(), corps.end(), tete);
    ++iterateur;

    // Si l'itérateur arrive au bout du corps revenir juste après la tête
    if (iterateur >= corps.end()) {
        iterateur = corps.begin();
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
    *iterateur = tete;

    // Controle si il a atteint la pomme
    if (tete == posPomme) {
        mangePomme(iterateur);
    }
}


// https://stackoverflow.com/questions/583076/c-c-changing-the-value-of-a-const
void Snake::initTailleFenetre(int largeurFenetreRecu, int longeurFenetreRecu) {
    largeurFenetre = largeurFenetreRecu;
    longeurFenetre = longeurFenetreRecu;
}

void Snake::setTete() {
    Coordonnee bas = DEPLACEMENTS_AUTORISE[2];

    for (size_t i = 0; i < corps.size(); ++i) {
        corps.at(i) += DEPLACEMENTS_AUTORISE.at(1);
        corps.at(i).setCouleur(0,0,0);
    }

}

void Snake::mangePomme(Corps::iterator iterateur) {
    ajouteCorps(iterateur, valPomme);
    creationPomme();
}

Snake::~Snake() {
    corps.clear();
}

void Snake::ajouteCorps(Corps::iterator iterateur, int taille) {
    corps.insert(iterateur, taille, Coordonnee(tete.getX(), tete.getY(), 0,0,0));
}

void Snake::serpentEstMange(Coordonnee impacte) {
    Corps::iterator iterateurImpacte = std::find(corps.begin(), corps.end(), impacte);
    Corps::iterator iterateurTete = std::find(corps.begin(), corps.end(), tete);

    if (iterateurTete < iterateurImpacte) {
        corps.erase(iterateurTete + 1, iterateurImpacte);
    }
    else {
        corps.erase(corps.begin(), iterateurImpacte);
        corps.erase(iterateurTete, corps.end());
    }
}

void Snake::serpentMange(size_t taille) {
    ajouteCorps(std::find(corps.begin(),corps.end(),tete),taille);
}

void Snake::serpentEstMort() {
    std::cout << ID << " est mort" << std::endl;
    this->~Snake();
}

const int Snake::getId() const {
    return ID;
}