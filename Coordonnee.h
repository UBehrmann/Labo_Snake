//------------------------------------------------------------------------------
// Fichier      Coordonnee.h
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

#ifndef SURVIVOR_COORDONNEE_H
#define SURVIVOR_COORDONNEE_H


class Coordonnee {
public:

    // Constructeur par défaut met en blanc
    Coordonnee() : x(0), y(0), r(255), g(255), b(255) {};

    // Constructeur
    Coordonnee(int x, int y, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255);

    // Fonction qui défini la couleur d'un pixel
    // Paramètres
    //  r      : quantité de rouge
    //  g      : quantité de vert
    //  b      : quantité de bleu
    void setCouleur(unsigned char r, unsigned char g, unsigned char b);

    // Fonction qui retourne la coordonée x
    int getX() const;

    // Fonction qui retourne la coordonée y
    int getY() const;


    // Fonction qui retourne la quantité de rouge
    unsigned char getR() const;

    // Fonction qui retourne la quantité de vert
    unsigned char getG() const;

    // Fonction qui retourne la quantité de bleu
    unsigned char getB() const;

    // Fonction qui afecte une nouvelle coordonnée x
    void setX(int x);

    // Fonction qui afecte une nouvelle coordonnée y
    void setY(int y);

    // Fonction qui afecte des nouvelles coordonnée x et y
    void setXY(int x, int y);

    // Fonction qui déclare l'opérateur += pour des coordonnées
    // Paramètres
    // c        : la coordonée
    void operator+=(const Coordonnee c);

    // Fonction qui déclare l'opérateur = pour des coordonnées
    // Paramètres
    // c        : la coordonée
    Coordonnee& operator=(const Coordonnee c);

    // Fonction qui déclare l'opérateur != pour des coordonnées
    // Paramètres
    // c        : la coordonée
    bool operator!=(const Coordonnee c) const;

    // Fonction qui déclare l'opérateur == pour des coordonnées
    // Paramètres
    // c        : la coordonée
    bool operator==(const Coordonnee c) const;

    // Fonction qui contrôle s'il y a déjà autre chose à cette position
    // Paramètres
    //  coordonne   : la coordonée à controler
    bool memePos(Coordonnee coordonne);

private:
    // Position
    int x;
    int y;

    // Couleurs
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif //SURVIVOR_COORDONNEE_H