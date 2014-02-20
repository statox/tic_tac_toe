#ifndef HUMAIN_H
#define HUMAIN_H

#include "Joueur.h"
class Plateau;

class Humain : public Joueur
{
    public:
        Humain(string nom, char symbole);

        /* cette fonction renvoit la case sur laquelle l'humain decide de jouer*/
        virtual Coordonnees choisirCase(Plateau plateau);
    protected:
    private:
};

#endif // HUMAIN_H
