#include "Partie.h"
#include <stdlib.h>
// constructeur par defaut pour gagner du temps pendant les tests
// a supprimer dans la version finale
Partie::Partie(int a)
{
    plateau = new Plateau(5, 5, 3);
//    plateau = new Plateau("plateau.txt");

    j1 = new Humain("joueur 1", 'X');
    j2 = new Humain("joueur 2", 'O');

    j1->SetnumeroTour(-1);
    j1->SetJoueEnPremier(false);
    j2->SetnumeroTour(1);
    j2->SetJoueEnPremier(true);

    cout << "\t creation d'une partie par defaut:" << endl;
    cout << "la partie oppose : " << endl;
    cout << j1->Getnom() << " qui joue les " << j1->Getsymbole() << " et joue en " << j1->GetnumeroTour() << "e" << endl;
    cout << "a " << endl;
    cout << j2->Getnom() << " qui joue les " << j2->Getsymbole() << " et joue en " << j2->GetnumeroTour() << "e" << endl;

    cout << "sur un plateau " << plateau->GetnbColonnes() << "x" << plateau->GetnbLignes() << " ou il faut aligner " << plateau->GetnbAlign() << " pions pour gagner" << endl << endl;
}

Partie::Partie()
{

    int c, l, a;
    cout << "\tcreation de la partie:" << endl << endl;

    // creation du plateau
    cout << "saisissez le nombre de colonnes du plateau: ";
    cin >> c;
    cout << "saisissez le nombre de lignes du plateau: ";
    cin >> l;
    cout << "saisissez le nombre de symboles a aligner pour gagner: ";
    cin >> a;
    plateau = new Plateau(c, l, a);

    // creation du premier joueur
    char choix = 'a';
    while (choix != 'h' && choix != 'm'){
        cout << endl << "le premier joueur doit il etre humain ou machine (saisissez h ou m): ";
        cin >> choix;
    }
    string nom;
    cout << "saisissez son nom: ";
    cin >> nom;

    if (choix=='h')
        j1 = new Humain(nom, 'X');
    else
        j1 = new Machine(nom, 'X');


    // creation du deuxieme joueur
    choix = 'a';
    while (choix != 'h' && choix != 'm'){
        cout << endl << "le deuxieme joueur doit il etre humain ou machine (saisissez h ou m): ";
        cin >> choix;
    }
    cout << "saisissez son nom: ";
    cin >> nom;

    if (choix=='h')
        j2 = new Humain(nom, 'O');
    else
        j2 = new Machine(nom, 'O');
    // choix de qui commence la partie
    int choixTour=0;
    cout << j1->Getnom() << " doit il jouer en premier? (0/1) ";
    cin >> choixTour;

    if (choixTour==0){
        j1->SetnumeroTour(-1);
        j1->SetJoueEnPremier(false);
        j2->SetnumeroTour(1);
        j2->SetJoueEnPremier(true);
    }else{
        j1->SetnumeroTour(1);
        j1->SetJoueEnPremier(true);
        j2->SetnumeroTour(-1);
        j2->SetJoueEnPremier(false);
    }

    cout << endl << endl;
    cout << "la partie oppose : " << endl;
    cout << j1->Getnom() << " qui joue les " << j1->Getsymbole() << endl;
    cout << "a " << endl;
    cout << j2->Getnom() << " qui joue les " << j2->Getsymbole() << endl;

    cout << "sur un plateau " << plateau->GetnbColonnes() << "x" << plateau->GetnbLignes() << " ou il faut aligner " << plateau->GetnbAlign() << " pions pour gagner" << endl << endl;
    cout << endl << endl;
}

void Partie::jouer()
{
    int t=0;
    plateau->afficher(j1, j2);
    int victoire=0;

    do{
        t++;
        cout << endl;
        if (t%2==1){
            if (j1->GetJoueEnPremier()){
                cout << "tour de " << j1->Getnom() << endl;
                plateau->marquer(j1->choisirCase(plateau), j1);
            }else{
                cout << "tour de " << j2->Getnom() << endl;
                plateau->marquer(j2->choisirCase(plateau), j2);
            }
        }else{
            if (j1->GetJoueEnPremier()){
                cout << "tour de " << j2->Getnom() << endl;
                plateau->marquer(j2->choisirCase(plateau), j2);
            }else{
                cout << "tour de " << j1->Getnom() << endl;
                plateau->marquer(j1->choisirCase(plateau), j1);
            }
        }
        plateau->afficher(j1, j2);

        victoire = finPartie();

        system("pause");
    }while (victoire==0);

    cout << "victoire de ";
    if (victoire==j1->GetnumeroTour())
        cout << j1->Getnom();
    else
        cout << j2->Getnom();

}

int Partie::finPartie()
{
    return plateau->masquePlein();
}
