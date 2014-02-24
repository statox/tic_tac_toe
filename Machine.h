#ifndef MACHINE_H
#define MACHINE_H

#include "Joueur.h"

class Plateau;
class Machine : public Joueur
{
    public:
        Machine(string nom, char symbole);

        void Setniveau(int val) { niveau = val; }
        int Getniveau() { return niveau; }

        /* cette fonction renvoit la case sur laquelle la machine decide de jouer*/
        Coordonnees choisirCase(Plateau* plateau);

        /* cette methode est appellee par la methode choisirCase*/
        Coordonnees choixAleatoire(Plateau* plateau);
    protected:
    private:
        int niveau;
};

#endif // MACHINE_H
