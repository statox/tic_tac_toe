#include <iostream>
#include "Partie.h"

#include <stdlib.h>
#include <math.h>

using namespace std;

void partieAdefinir();
void partiePredefinie();
void partieStatistiques(int nbPartie);

int main()
{

    partieAdefinir();
//    partiePredefinie();
//    partieStatistiques(50);

    return 0;
}

void partieAdefinir()
{
    Partie* partie = new Partie();
    partie->jouer();
}

void partiePredefinie()
{
    Partie* partie = new Partie(1);
    partie->jouer();
}

void partieStatistiques(int nbPartie){
    int j1=0, j2=0, ega=0;
    int cpt=0;
    int resultat=0;

    do{
        Partie* partie = new Partie(1);
        resultat = partie->jouer();

        if (resultat==1)
            j1++;
        else if (resultat==-1)
            j2++;
        else if (resultat==-10)
            ega++;

        cpt++;
        cout << endl << endl << "joueur 1: " << j1 << "  joueur 2: " << j2 << "  egalite: " << ega << endl << endl;
        system("pause");
        partie->~Partie();

    }while(cpt < nbPartie);

    cout << "joueur 1: " << j1 << "  joueur 2: " << j2 << "  egalite: " << ega << endl << endl;
}
