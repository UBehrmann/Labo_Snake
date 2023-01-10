//------------------------------------------------------------------------------
// Fichier      Annexe.h
// Auteur       Urs Behrmann et Calum Quinn
// Date         09.01.2023
//
// But          Fournit une fonction generant un nombre aleatoir entre deux bornes.
//              Fournit une fonction gerant la saisie de l'utilisateur.
//              (prenant en compte les erreurs de saisie)
//
// Remarque
//
// Modifs       n/a
//
// Compilateur  MinGW w64 9.0
//------------------------------------------------------------------------------

#ifndef LABO_ROBOT_ANNEXE_H
#define LABO_ROBOT_ANNEXE_H

#include <string> //Pour les saisies

/**---------------------------------------------------------------------------------
 * Génére un nombre entier aléatoire entre une valeur minimale et une valeur maximale.
 * D'après la demo 04_random.cpp.
 * https://github.com/gmbreguet/PRG1_DEMO/blob/main/04_Fonctions/04_random.cpp
 * @param valMin  : valeur minimale que la fonction pourra retrourner.
 * @param valMax  : valeur maximale que la fonction pourra retrourner.
 * @return        : un entier aleatoire entre valMin et valMax.
 * @exception     : - (Aucune exception).
 */
template <typename T>
T nbAleatoire(T valMin, T valMax);


/** ---------------------------------------------------------------------------------
* Contrôle de la saisie utilisation en fonction de borne min et max
* D'après le prg du git DEMO
* https://github.com/gmbreguet/PRG1_DEMO
* @param msgInvite : Message pour inviter la saisie utilisateur
* @aram msgErreur  : Message a affiché en cas d'erreur de saisie
* @param min       : Borne de minimal de la saisie
* @param max       : Borne maximal de la saisie
* @return          : Valeur saisie par l'utilisateur (un int)
* @exception       : - (Aucune exception)
*/
template <typename output, typename input>
output saisie(const std::string& msgInvite,const std::string& msgErreur,
           const input& min,const input& max);



#endif //LABO_ROBOT_ANNEXE_H