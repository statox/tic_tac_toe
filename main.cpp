#include <iostream>
#include "Partie.h"
#include "Coordonnees.h"
#include "templates.h"

using namespace std;


int main()
{
//    Partie partie(1);
//    partie.jouer();

    Plateau p(10,10,1);
    p.creerMasques();


    return 0;
}
