#include <iostream>
#include "Partie.h"

#include <stdlib.h>

using namespace std;

void partieAdefinir();
void partiePredefinie();
void partieStatistiques(int nbPartie);

int main()
{

    partieAdefinir();
//    partiePredefinie();
//    partieStatistiques(20);

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
    int jaleat=0, jminmax=0, ega=0;
    int cpt=0;
    int resultat=0;

    do{
        Partie* partie = new Partie(1);
        resultat = partie->jouer();

        if (resultat==1)
            jaleat++;
        else if (resultat==-1)
            jminmax++;
        else if (resultat==-10)
            ega++;

        cpt++;
        cout << endl << endl << "aleatoire: " << jaleat << "  minmax: " << jminmax << "  egalite: " << ega << endl << endl;
//        system("pause");
        partie->~Partie();

    }while(cpt < nbPartie);

    cout << "aleatoire: " << jaleat << "  minmax: " << jminmax << "  egalite: " << ega << endl;
}
