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

GameMaster::GameMaster() {

}

void GameMaster:: init() {
    int longeurFenetre;
    int largeurFenetre;
    size_t nbreSerpents;

    // Saisies
    longeurFenetre = saisie<int>("", "", 80, 200);
    largeurFenetre = saisie<int>("", "", 80, 200);
    nbreSerpents = saisie<size_t>("", "", 5, 20);

    // Init fenêtre
    fenetre.initFenetre(longeurFenetre, largeurFenetre);

    // Init serpents
    serpents.resize(nbreSerpents);

    // Remplir vecteur de serpents en contrôlant de ne pas en avoir au même endroit
    Coordonnee position;
    for (size_t i = 0; i < nbreSerpents; ++i) {
        do {
            position = {nbAleatoire<int>(0,largeurFenetre), nbAleatoire<int>(0,longeurFenetre)};
        } while (serpents[i].getTete() == position);
    }

    serpents.push_back(Snake(position));

}



void GameMaster::update() {
    std::vector<Coordonnee> pixels;

    // Update serpents



    // Update Affichage

    // Ajoute tous les corps des serpents et les pommes a un vecteur de pixels
    for (const Snake& serpent : serpents) {
        pixels.insert(pixels.end(), serpent.getCorps().begin(), serpent.getCorps().end());
        pixels.push_back(serpent.getPomme());
    }

    fenetre.update(pixels);
}

bool GameMaster::appIsRunning() const {
    return fenetre.appIsRunning;
}


