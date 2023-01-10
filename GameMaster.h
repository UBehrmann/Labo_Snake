//------------------------------------------------------------------------------
// Fichier      GameMaster.h
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

#ifndef LABO_SNAKE_GAMEMASTER_H
#define LABO_SNAKE_GAMEMASTER_H

#include <vector>
#include "Fenetre.h"
#include "Snake.h"

class GameMaster {
private:
public:
    GameMaster();

    void update();

    void init();

    bool appIsRunning() const;

private:
    std::vector<Snake> serpents;

    Fenetre fenetre;
};


#endif //LABO_SNAKE_GAMEMASTER_H
