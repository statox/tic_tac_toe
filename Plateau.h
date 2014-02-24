#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
using namespace std;

#include <vector>
#include "Coordonnees.h"

class Joueur;

class Plateau
{
    private:
        int** plateau;
        int nbColonnes;
        int nbLignes;
        int nbAlign;
        vector< vector<Coordonnees> > masques; // masque est un veccteur contenant des vecteurs de coordonnées

    public:
        Plateau(int col, int lig, int align);
        // creation du plateau a partir d'un fichier
        Plateau(string chemin);
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

        // cette fonction est appellée par le constructeur du plateau. Elle crée l'ensemble des masques du plateau (les alignements possibles)
        // et les stocke dans masques
        void creerMasques();

        // cette fonction verifie si l'un des masques est plein et renvoit le chiffre qui le remplit
        int masquePlein();

        void afficher(Joueur* j1, Joueur* j2);
        void marquer(Coordonnees c, Joueur* j);
};

#endif // PLATEAU_H
