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
    for (int i=0; i<nbLignes; i++)
        delete[] plateau[i];

    delete[] plateau;
}

void Plateau::afficher(Joueur* j1, Joueur* j2)
{
    for (int i=0; i < nbLignes; i++){
        for (int j=0; j < nbColonnes; j++){
            if (plateau[i][j]==j1->GetnumeroTour())
                cout << j1->Getsymbole() << " ";
            else if (plateau[i][j]==j2->GetnumeroTour())
                cout << j2->Getsymbole() << " ";
            else
                cout << "." << " ";
        }
        cout << endl;
    }
}

void Plateau::marquer(Coordonnees c, Joueur* j){

    if (Getcase(c)==0 /*&& c est dans le plateau*/){
        cout << "on va marquer la case " << c << " avec le numero " << j->GetnumeroTour() << endl;
        plateau[c.Getlig()][c.Getcol()] = j->GetnumeroTour();
    }
    else
    {
        cout << "case invalide echec du tour" << endl;
    }
}

void Plateau::creerMasques()
{
    std::list <int* > masques;


}
