//------------------------------------------------------------------------------
// Fichier      Coordonnee.h
// Auteur       Urs Behrmann et Calum Quinn
// Date         09.01.2023
//
// But          Class qui sert a stocker et transmettre des donnees de position et de couleur
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

    /**
     * @name        : Coordonnee
     *
     * @but         : Constructeur de Coordonnee
     *
     * @param x     : coordonnee x
     * @param y     : coordonnee y
     * @param r     : quantite de rouge
     * @param g     : quantite de vert
     * @param b     : quantite de bleu
     * @return      : void
     * @throws      : NIL
     */
    Coordonnee() : x(0), y(0), r(255), g(255), b(255) {};

    /**
     * @name        : Coordonnee
     *
     * @but         : Constructeur de Coordonnee dans lequel la couleur est sette a blanc
     *
     * @param x     : coordonnee x
     * @param y     : coordonnee y
     * @return      : void
     * @throws      : NIL
     */
    Coordonnee(int x, int y, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255);

    /**
     * @name        : setCouleur
     *
     * @but         : Fonction qui défini la couleur d'un pixel
     *
     * @param r     : quantite de rouge
     * @param g     : quantite de vert
     * @param b     : quantite de bleu
     * @return      : void
     * @throws      : NIL
     */
    void setCouleur(unsigned char r, unsigned char g, unsigned char b);

    /**
     * @name        : getX
     *
     * @but         : Fonction qui retourne la coordonnée x
     *
     * @return      : coordonnee x
     * @throws      : NIL
     */
    int getX() const;

    /**
     * @name        : getX
     *
     * @but         : Fonction qui retourne la coordonnée y
     *
     * @return      : coordonnee y
     * @throws      : NIL
     */
    int getY() const;

    /**
     * @name        : getR
     *
     * @but         : Fonction qui retourne la quantité de rouge
     *
     * @return      : quantité de rouge
     * @throws      : NIL
     */
    unsigned char getR() const;

    /**
     * @name        : getG
     *
     * @but         : Fonction qui retourne la quantité de vert
     *
     * @return      : quantité de vert
     * @throws      : NIL
     */
    unsigned char getG() const;

    /**
     * @name        : getB
     *
     * @but         : Fonction qui retourne la quantité de bleu
     *
     * @return      : quantité de bleu
     * @throws      : NIL
     */
    unsigned char getB() const;

    /**
     * @name        : setXY
     *
     * @but         : Fonction qui affecte des nouvelles coordonnées x et y
     *
     * @param x     : coordonnee x
     * @param y     : coordonnee y
     * @return      : void
     * @throws      : NIL
     */
    void setXY(int x, int y);

    /**
     * @name        : operator+=
     *
     * @but         : Fonction qui déclare l'opérateur += pour des coordonnées
     *
     * @param c     : la coordonnee
     * @return      : void
     * @throws      : NIL
     */
    void operator+=(Coordonnee c);

    /**
     * @name        : operator=
     *
     * @but         : Fonction qui déclare l'opérateur = pour des coordonnées
     *
     * @param c     : la coordonnee
     * @return      : La coordonnee mais affecte par la coordonnee c
     * @throws      : NIL
     */
    Coordonnee& operator=(Coordonnee c);

    /**
     * @name        : operator!=
     *
     * @but         : Fonction qui déclare l'opérateur != pour des coordonnées
     *
     * @param c     : la coordonnee
     * @return      : Vrai, si ils ne sont pas egal sinon Faux
     * @throws      : NIL
     */
    bool operator!=(Coordonnee c) const;

    /**
     * @name        : operator==
     *
     * @but         : Fonction qui déclare l'opérateur == pour des coordonnées
     *
     * @param c     : la coordonnee
     * @return      : Vrai, si ils sont egaux sinon Faux
     * @throws      : NIL
     */
    bool operator==(Coordonnee c) const;

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