//------------------------------------------------------------------------------
// Fichier      Annexe.cpp
// Auteur       Uhr Behrmann et Calum Quinn
// Date         09.01.2023
//
// But          Developement des fonctions de la librairie "annexe".
//
// Remarque
//
// Modifs       n/a
//
// Compilateur  MinGW w64 9.0
//------------------------------------------------------------------------------

#include "annexe.h"

#include <random>   //Pour les nombres aléatoire
#include <iostream> //Pour les saisies
#include <limits>   //Pour vider le buffer

using namespace std;

/* ---------------------------------------------------------------------------------
 * Permet d'obtenir un nombre aleatoire entre une valeur min et max.
 * D'après la demo 04_random.cpp.
 * https://github.com/gmbreguet/PRG1_DEMO/blob/main/04_Fonctions/04_random.cpp
 */
int nbAleatoire(int valMin, int valMax) {
    random_device rand_dev;
    default_random_engine generator(rand_dev());
    uniform_int_distribution<int> distr(valMin, valMax);

    return distr(generator);
}

/* ---------------------------------------------------------------------------------
 * Contrôle de la saisie utilisation en fonction de borne min et max
 * https://github.com/gmbreguet/PRG1_DEMO
 */
int saisie(const string& msgInvite, const string& msgErreur, const int& min, const int& max) {

    int         saisie;    // ne peuvent pas être déclarés
    bool        erreur;    // ... dans la boucle

    do {
        // saisie et vérification
        cout << msgInvite << " [" << min << " - " << max << "] : ";
        erreur = not(cin >> saisie) or saisie < min or saisie > max;

        // gestion du flux
        if (erreur) {
            cout << msgErreur << endl;
            cin.clear();
        }

        // vider buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while(erreur);
    // retour de la valeur saisie
    return saisie;
}