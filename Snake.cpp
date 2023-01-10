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

Snake::Snake() {

}

Snake::Snake(Coordonnee position){
    this->tete = position;
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
    this->posPomme = {nbAleatoire(0, largeurFenetre), nbAleatoire(0, longeurFenetre)};
    this->valPomme = nbAleatoire(1,10);
}

void Snake::bouge() {


}

// https://stackoverflow.com/questions/583076/c-c-changing-the-value-of-a-const
void Snake::initTailleFenetre(int largeurFenetreRecu, int longeurFenetreRecu) {
    int *ptr;

    ptr = const_cast<int*>( &this->largeurFenetre);
    *ptr = largeurFenetreRecu;

    ptr = const_cast<int*>( &this->longeurFenetre);
    *ptr = longeurFenetreRecu;
}
