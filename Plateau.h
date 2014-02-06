#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
using namespace std;

#include "Coordonnees.h"

class Plateau
{
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

        void Setcase(Coordonnees c, int val) {cout << "coucou" << endl; plateau[c.Getlig()][c.Getcol()] = val; cout << "caca" << endl; }
        int Getcase(Coordonnees c) { return plateau[c.Getlig()][c.Getcol()]; }

        void afficher();
    protected:
    private:
        int** plateau;
        int nbColonnes;
        int nbLignes;
        int nbAlign;
};

#endif // PLATEAU_H
