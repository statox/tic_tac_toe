#include <iostream>
#include "Partie.h"
#include "Coordonnees.h"

using namespace std;


int main()
{
//    Partie partie;
//
//    partie.Getplateau().afficher();

    Plateau p(10, 5, 3);

    Humain j("nom", 'X');

    j.SetnumeroTour(3);

    p.Setcase(Coordonnees(0,0), 2);
    p.afficher();



    p.marquer(j.choisirCase(p), j);;


    cout << "pouet" << endl;


    return 0;
}
