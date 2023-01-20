//------------------------------------------------------------------------------
// Fichier      GameMaster.cpp
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

#include "GameMaster.h"
#include "Annexe.h"
#include "Coordonnee.h"

#include <chrono> // Pour ralentir l'affichage
#include <thread> // Pour ralentir l'affichage
#include <string> // Messages d'erreur

using namespace std;

GameMaster::GameMaster() = default;

void GameMaster::init() {

    const string messageErreur = "Mauvaise saisie, veuillez recommencer.";

    // Saisies utilisateur
    int longeurFenetre = saisie("Longeur fenetre", messageErreur, 80, 200);
    int largeurFenetre = saisie("Largeur fenetre", messageErreur, 80, 200);
    size_t nbreSerpents = (size_t)saisie("Nbre de serpents", messageErreur, 5, 20);

    // Initialisation fenêtre
    fenetre.initFenetre(largeurFenetre, longeurFenetre);
    Snake::initTailleFenetre(largeurFenetre, longeurFenetre);

    // Remplir vecteur de serpents en contrôlant de ne pas en avoir au même endroit
    Coordonnee position;
    for (size_t i = 0; i < nbreSerpents; ++i) {
        do {
            position = {nbAleatoire(0,largeurFenetre), nbAleatoire(0,longeurFenetre)};
        } while (estOccupe(position));

        serpents.emplace_back(position, i);
    }
}


void GameMaster::update() {
    // Met à jour les serpents et l'affichage
    updateSerpents();
    affichage();
}

bool GameMaster::appIsRunning() const {
    return fenetre.appIsRunning;
}

bool GameMaster::estOccupe(Coordonnee coordonnee) {
    for ( const Snake& serpent : serpents)
        if ( serpent.getTete() == coordonnee )
            return true;

    return false;
}

void GameMaster::affichage() {
    // Déclare un vecteur pour stocker les éléments à afficher
    std::vector<Coordonnee> pixels;

    // Ajoute tous les corps des serpents et les pommes a un vecteur de pixels
    for (Snake& serpent : serpents) {
        pixels.insert(pixels.end(), serpent.getCorps().begin(), serpent.getCorps().end());
        pixels.push_back(serpent.getPomme());
    }

    // Met à jour l'affichage
    fenetre.update(pixels);

    // Retarde l'affichage pour qu'on voie les déplacements
    this_thread::sleep_for(100ms); //JE TROUVE QUE 20MS CA DONNE MIEUX
}

void GameMaster::updateSerpents() {


    // Met à jour chaque serpent
    for (Snake& i : serpents)
        i.bouge();

    // Test pour collisions entre les serpents
    for (Snake& i : serpents) {
        for (Snake& j : serpents) {
            // Si ce n'est pas lui-même et qu'il y a une collision
            if (j != i && checkCollision(i, j)) {
                gestionCollision(i, j);
            }
        }
    }
}

void GameMaster::serpentEstMort(Snake& serpentMort, Snake& serpentTueur) {

    // Affichage de texte de mort
    serpentMort.serpentEstMort(serpentTueur);

    // Supprime le serpentMort du vecteur de serpents
    serpents.erase(find(serpents.begin(), serpents.end(), serpentMort));
}

bool GameMaster::checkCollision(const Snake& serpent1, const Snake& serpent2){
    // Check si la tete du serpent1 est sur une position du corps du serpent2
    return serpent2.getCorps().end() != find(serpent2.getCorps().begin(), serpent2.getCorps().end(), serpent1.getTete());
}

void GameMaster::gestionCollision(Snake& serpent1, Snake& serpent2){

    // Test si c'est une collision entre deux tetes ou pas
    if (serpent1.getTete() == serpent2.getTete()){

        // Trouve le serpent le plus grand et tue l'autre
        if (serpent1.getCorps().size() > serpent2.getCorps().size()) {
            serpent1.serpentMange(int(serpent2.getCorps().size()) * 10 / 6);
            serpentEstMort(serpent2, serpent1);
        }
        else {
            serpent2.serpentMange(int(serpent1.getCorps().size()) * 10 / 6);
            serpentEstMort(serpent1, serpent2);
        }
    }
    else{
        // Trouve la position de l'impacte du serpent attaque
        for (size_t k = 0; k < serpent2.getCorps().size(); ++k) {
            if(serpent1.getTete() == serpent2.getCorps()[k]){
                serpent1.serpentMange(serpent2.getCorps().size() - k);
                serpent2.serpentEstMange(serpent2.getCorps()[k]);
                break;
            }
        }
    }
}
