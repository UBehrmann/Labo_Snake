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

#include <random>   //Pour les nombres aléatoire
#include <iostream> //Pour les saisies
#include <limits>   //Pour vider le buffer

#include "annexe.h"

using namespace std;

/* ---------------------------------------------------------------------------------
 * Permet d'obtenir un nombre aleatoire entre une valeur min et max.
 * D'après la demo 04_random.cpp.
 * https://github.com/gmbreguet/PRG1_DEMO/blob/main/04_Fonctions/04_random.cpp
 */
template <typename T>
T nbAleatoire(T valMin, T valMax) {
    random_device rand_dev;
    default_random_engine generator(rand_dev());
    uniform_int_distribution<T> distr(valMin, valMax);

    return distr(generator);
}

/* ---------------------------------------------------------------------------------
 * Contrôle de la saisie utilisation en fonction de borne min et max
 * https://github.com/gmbreguet/PRG1_DEMO
 */
template <typename output, typename input>
output saisie(const string& msgInvite, const string& msgErreur, const input& min, const input& max) {

    output       saisie;    // ne peuvent pas être déclarés
    bool         erreur;    // ... dans la boucle

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