#include "Machine.h"
#include "Plateau.h"

#include <stdlib.h>
#include <time.h>

Machine::Machine(string nom, char symbole) : Joueur(nom, symbole)
{
    int niv;
    cout << "saisissez le niveau de force de la machine: ";
    cin >> niv;

    Setniveau(niv);
}

Coordonnees Machine::choisirCase(Plateau* plateau)
{
//    cout << "Pour l'instant je ne sais pas choisir de case" << endl;
//    return Coordonnees (0,0);
    Coordonnees c = choixAleatoire(plateau);
    cout << "Je choisi au hasard: " << c << endl;
    return c;
}

Coordonnees Machine::choixAleatoire(Plateau* plateau)
{
    Coordonnees c;
    srand(time(NULL));
    int col, lig;

    do{
        col = rand()%(plateau->GetnbColonnes());
        lig = rand()%(plateau->GetnbLignes());

        c.Setcol(col);
        c.Setlig(lig);
    }while(plateau->Getcase(c)!=0);

    return c;
}
