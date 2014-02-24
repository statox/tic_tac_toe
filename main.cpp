#include <iostream>
#include "Partie.h"
#include "Coordonnees.h"
#include "templates.h"
#include "NoeudMinMax.h"

using namespace std;


int main()
{

//    Partie* partie = new Partie(1);
//    partie->jouer();

    Joueur* j1 = new Humain("kiki", 'O');
    Joueur* j2 = new Humain("vivi", 'X');

    j1->SetnumeroTour(-1);
    j2->SetnumeroTour(1);

    Plateau* p = new Plateau("plateau.txt");
    p->afficher(j1, j2);
//    p->evaluation();

    NoeudMinMax* n = new NoeudMinMax(*p);
    n->Getplateau()->afficher(j1, j2);

    return 0;
}
