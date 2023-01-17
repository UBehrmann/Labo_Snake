//------------------------------------------------------------------------------
// Fichier      GameMaster.cpp
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
    fenetre.initFenetre(longeurFenetre, largeurFenetre);
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

bool GameMaster::estOccupe(Coordonnee c) {
    for ( const Snake& s : serpents)
        if ( s.getTete() == c )
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
    for (Snake& i : serpents) {
        i.bouge();
        // Contrôle tous les serpents
        for (Snake& j : serpents) {
            // Si ce n'est pas lui même
            if (j != i) {
                // Contrôle toutes les parties du corp
                for (size_t k = 0; k < j.getCorps().size(); ++k) {
                    // S'il mort
                    if (i.getTete() == j.getCorps()[k]) {
                        // La tête
                        if (j.getCorps()[k] == j.getTete()) {
                            if (i.getCorps().size() > j.getCorps().size()) {
                                i.serpentMange(j.getCorps().size() * 10 / 6);
                                serpents.erase(find(serpents.begin(),serpents.end(),j));
                                j.serpentEstMort();
                            }
                            else {
                                j.serpentMange(i.getCorps().size() * 10 / 6);
                                serpents.erase(find(serpents.begin(),serpents.end(),i));
                                i.serpentEstMort();
                            }
                        }
                        // Ailleurs que la tête
                        else {
                            // Celui qui est mangé
                            j.serpentEstMange(j.getCorps()[k]);
                        }
                    }
                }
            }
        }
    }
}


