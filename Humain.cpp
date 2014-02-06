#include "Humain.h"

Humain::Humain(string nom, char symbole) : Joueur(nom, symbole)
{
    //ctor
}

Coordonnees Humain::choisirCase(Plateau plateau)
{
    int col=-1, lig=-1;
    Coordonnees c;

//    do{
        do{
            cout << "Choisissez la colonne dans laquelle vous souhaitez jouer: ";
            cin >> col;
        }while (col<0 || col > plateau.GetnbColonnes());

        do{
            cout << "Choisissez la ligne dans laquelle vous souhaitez jouer: ";
            cin >> lig;
        }while (lig<0 || lig > plateau.GetnbLignes());

        c.Setcol(col);
        c.Setlig(lig);

        cout << "coordonnee: " << c << endl;

//    }while(plateau.Getcase(c)!=0);

    return c;
}
