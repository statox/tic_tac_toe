#ifndef MACHINE_H
#define MACHINE_H

#include "Joueur.h"
#include "NoeudMinMax.h"

class Plateau;
class Machine : public Joueur
{
    public:
        Machine(string nom, char symbole, int type, int force);
        Machine(string nom, char symbole);

        void Setniveau(int val) { niveau = val; }
        int Getniveau() { return niveau; }

        void SettypeIA(int val) { typeIA = val; }
        int GettypeIA() { return typeIA; }

        /* cette fonction renvoit la case sur laquelle la machine decide de jouer*/
        Coordonnees choisirCase(Plateau* plateau);

        /* ces methodes est appellee par la methode choisirCase*/
        Coordonnees choixAleatoire(Plateau* plateau);
        int choixMinMax(NoeudMinMax n, Coordonnees* c_choisi);
        int choixMinMaxElagage(NoeudMinMax n, Coordonnees* c_choisi, int alpha, int beta);

    protected:
    private:
        int niveau;
        int typeIA;
};

#endif // MACHINE_H
