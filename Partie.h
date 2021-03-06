#ifndef PARTIE_H
#define PARTIE_H

#include "Humain.h"
#include "Machine.h"
#include "Plateau.h"

class Partie
{
    public:
        Partie();   // constructeur a utiliser dans la version finale qui demande les caracteristiques a l'utilisateur
        Partie(int a);  // constructeur qui entre tous les parametres par defaut pour gagner du temps pendant les tests
        ~Partie();

        Plateau* Getplateau() { return plateau; }
        Joueur Getj1() { return *j1; }
        Joueur Getj2() { return *j2; }

        int jouer();

        int finPartie();

    protected:
    private:
        Plateau* plateau;
        Joueur* j1;
        Joueur* j2;
};

#endif // PARTIE_H
