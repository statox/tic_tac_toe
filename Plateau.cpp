#include "Plateau.h"
#include "Joueur.h"

Plateau::Plateau(int col, int lig, int align)
{

    // initialisation variables du plateau
    SetnbColonnes(col);
    SetnbLignes(lig);
    SetnbAlign(align);

    // reservation du plateau
    plateau = new int* [nbLignes];
    int i;
    for (i=0; i<nbLignes; i++)
        plateau[i] = new int [nbColonnes];

    // initialisation du plateau
    for (int i=0; i < nbLignes; i++)
        for (int j=0; j < nbColonnes; j++)
            plateau[i][j] = 0;

}

Plateau::~Plateau()
{
    cout << "destruction" << endl;
    for (int i=0; i<nbLignes; i++)
        delete[] plateau[i];

    delete[] plateau;

    cout << "fin destruction" << endl;
}

void Plateau::afficher()
{
    for (int i=0; i < nbLignes; i++){
        for (int j=0; j < nbColonnes; j++){
            cout << plateau[i][j] << " ";
        }
        cout << endl;
    }
}

void Plateau::marquer(Coordonnees c, Joueur j){

//    if (Getcase(c)==0 /*&& c est dans le plateau*/){
//        plateau[c.Getlig()][c.Getcol()] == j.GetnumeroTour();
//    }
}
