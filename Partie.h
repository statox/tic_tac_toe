#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.h"
#include "Plateau.h"

class Partie
{
    public:
        Partie();
        Plateau Getplateau() { return plateau; }
        void Setplateau(Plateau val) { plateau = val; }
        Joueur Getj1() { return j1; }
        void Setj1(Joueur val) { j1 = val; }
        Joueur Getj2() { return j2; }
        void Setj2(Joueur val) { j2 = val; }
    protected:
    private:
        Plateau plateau;
        Joueur j1;
        Joueur j2;
};

#endif // PARTIE_H
