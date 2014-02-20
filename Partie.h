#ifndef PARTIE_H
#define PARTIE_H

#include "Humain.h"
#include "Machine.h"
#include "Plateau.h"

class Partie
{
    public:
        Partie();

        Plateau Getplateau() { return *plateau; }
        Joueur Getj1() { return *j1; }
        Joueur Getj2() { return *j2; }

        void jouer();

    protected:
    private:
        Plateau* plateau;
        Joueur* j1;
        Joueur* j2;
};

#endif // PARTIE_H
