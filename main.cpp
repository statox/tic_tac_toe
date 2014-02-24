#include <iostream>
#include "Partie.h"
#include "Coordonnees.h"
#include "templates.h"

using namespace std;


int main()
{

    Partie* partie = new Partie(1);

    partie->jouer();

    return 0;
}
