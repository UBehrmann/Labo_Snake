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

#include <iostream> // Pour annoncer les morts

#define VERT 0,255,0
#define COULEUR_SERPENT 0,0,0

int Snake::longeurFenetre;
int Snake::largeurFenetre;

Snake::Snake() : ID(-1), valPomme(1){
}

Snake:: Snake(Coordonnee position, int id) : ID(id), valPomme(1){
    // Réserve de la place pour que le serpent puisse grandir
    corps.reserve(200);

    // Assigne la position aléatoire à la tête
    tete = position;
    position.setCouleur(COULEUR_SERPENT);

    // Défini toutes les parties du corps à la même position que la tête
    for (size_t i = 0; i < size_t(tailleSerpent); ++i) {
        corps.push_back(position);
    }

    // Crée une pomme pour le serpent
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

bool Snake::operator!=(const Snake& s) const {
    return !(*this == s);
}

Snake& Snake::operator=(const Snake& s) {
    tete = s.tete;
    corps = s.corps;
    ID = s.ID;
    return *this;
}

void Snake::creationPomme() {
    // Place une pomme aléatoirement dans la fenêtre et lui assigne une valeur
    posPomme.setXY(nbAleatoire(0, largeurFenetre), nbAleatoire(0, longeurFenetre));
    posPomme.setCouleur(VERT);
    valPomme = nbAleatoire(2,10);
}

void Snake::bouge() {
    // Itérateur qui donne la prochaine case qui remplacera la tête
    Corps::iterator iterateur = std::find(corps.begin(), corps.end(), tete);
    ++iterateur;

    // Si l'itérateur arrive au bout du corps revenir juste après la tête
    if (iterateur >= corps.end()) {
        iterateur = corps.begin();
    }

    // Trouve la position relative à la pomme
    int distHorizontale = posPomme.getX() - tete.getX();
    int distVerticale   = posPomme.getY() - tete.getY();

    // Dirige le serpent en direction de la pomme
    if (abs(distHorizontale) > abs(distVerticale)) {
        tete += DEPLACEMENTS_AUTORISE[distHorizontale < 0 ? 3 : 1];
    }
    else {
        tete += DEPLACEMENTS_AUTORISE[distVerticale < 0 ? 0 : 2];
    }
    *iterateur = tete;

    // Controle si le serpent a atteint la pomme
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

    for (Coordonnee& i : corps) {
        i += DEPLACEMENTS_AUTORISE.at(1);
    }

}

void Snake::mangePomme(Corps::iterator iterateur) {
    // Fait grandir le serpent et place une nouvelle pomme
    ajouteCorps(iterateur, valPomme);
    creationPomme();
}

Snake::~Snake() {
    // Vide toutes les parties du corps
    corps.clear();
}

void Snake::ajouteCorps(Corps::iterator iterateur, int taille) {
    // Ajoute des parties tout à la fin du corps
    corps.insert(iterateur, size_t(taille), Coordonnee(tete.getX(), tete.getY(), COULEUR_SERPENT));
}

void Snake::serpentEstMange(Coordonnee impacte) {
    // Déclare des itérateurs pour la position de la tête et de la morçure
    Corps::iterator iterateurImpacte = std::find(corps.begin(), corps.end(), impacte);
    Corps::iterator iterateurTete = std::find(corps.begin(), corps.end(), tete);

    // Efface le corps nécessaire en fonction de l'impacte
    if (iterateurTete < iterateurImpacte) {
        corps.erase(iterateurTete + 1, iterateurImpacte);
    }
    else {
        corps.erase(corps.begin(), iterateurImpacte);
        corps.erase(iterateurTete, corps.end());
    }
}

void Snake::serpentMange(int taille) {
    // Ajoute des parties au serpent qui vient de mordre un autre
    ajouteCorps(std::find(corps.begin(),corps.end(),tete),taille);
}

void Snake::serpentEstMort() {
    // Met à jour les statistiques de mort et détruit le serpent mort
    std::cout << ID << " est mort" << std::endl;
    this->~Snake();
}

int Snake::getId() const {
    return ID;
}

bool Snake::operator==(const Snake& s) const {
    return this->ID == s.ID;
}
