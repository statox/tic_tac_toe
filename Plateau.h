#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
using namespace std;

#include "Coordonnees.h"
class Joueur;

class Plateau
{
    private:
        int** plateau;
        int nbColonnes;
        int nbLignes;
        int nbAlign;

    public:
        Plateau(int col, int lig, int align);
        ~Plateau();

        int** Getplateau() { return plateau; }
        void Setplateau(int** val) { plateau = val; }
        int GetnbColonnes() { return nbColonnes; }
        void SetnbColonnes(int val) { nbColonnes = val; }
        int GetnbLignes() { return nbLignes; }
        void SetnbLignes(int val) { nbLignes = val; }
        int GetnbAlign() { return nbAlign; }
        void SetnbAlign(int val) { nbAlign = val; }

        void Setcase(Coordonnees c, int val) {plateau[c.Getlig()][c.Getcol()] = val;}
        int Getcase(Coordonnees c) {if(c.Getlig()<GetnbLignes() && c.Getcol()<GetnbColonnes()){return plateau[c.Getlig()][c.Getcol()];}else{return -1;}}

        void afficher();
        void marquer(Coordonnees c, Joueur j);
};

#endif // PLATEAU_H
