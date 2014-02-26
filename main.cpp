#include <iostream>
#include "Partie.h"

using namespace std;


int main()
{

//    int jaleat=0, jminmax=0, ega=0;
//    int cpt=0;
//    int resultat=0;
//
//    do{
//        Partie* partie = new Partie(1);
//        resultat = partie->jouer();
//
//        if (resultat==1)
//            jaleat++;
//        else if (resultat==-1)
//            jminmax++;
//        else if (resultat==-10)
//            ega++;
//
//        cout << endl << endl << "aleatoire: " << jaleat << "  minmax: " << jminmax << "  egalite: " << ega << endl << endl;
//
//    }while(cpt < 20);
//
//    cout << "aleatoire: " << jaleat << "  minmax: " << jminmax << "  egalite: " << ega << endl;

    Partie* partie = new Partie();
    partie->jouer();

    return 0;
}
