#include "Machine.h"

Machine::Machine(string nom, char symbole) : Joueur(nom, symbole)
{
    int niv;
    cout << "saisissez le niveau de force de la machine: ";
    cin >> niv;

    Setniveau(niv);
}

Coordonnees Machine::choisirCase(Plateau plateau)
{
    cout << "Pour l'instant je ne sais pas choisir de case" << endl;
}
