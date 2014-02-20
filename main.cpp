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
    p.afficher();
//
//    cout << endl;
//
//    p.Setcase(Coordonnees (0,0), 2);
//    p.afficher();
//
//    cout << endl;
//
//    cout << "tests get case: " << endl;
//    cout << p.Getcase(Coordonnees(0,0)) << p.Getcase(Coordonnees(5,5)) << endl;

    Humain h("humain", 'X');
    h.SetnumeroTour(0);

    Machine m("machine", 'O');
    m.SetnumeroTour(1);

    cout << "case choisie par l'humain: " << endl << p.Getcase(h.choisirCase(p)) << endl;


//    p.marquer(j.choisirCase(p), j);


    return 0;
}
