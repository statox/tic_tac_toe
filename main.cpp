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


    p.afficher();

    j.choisirCase(p);


    cout << "pouet" << endl;


    return 0;
}
