#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <iostream>
using namespace std;

#include "Coordonnees.h"

class Plateau;  // forward délcaration pour pouvoir utiliser la classe dans la méthode choisirCase()
class Joueur
{
    public:
        Joueur(string n, char s);
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        char Getsymbole() { return symbole; }
        void Setsymbole(char val) { symbole = val; }
        int GetnumeroTour() { return numeroTour; }
        void SetnumeroTour(int val) {numeroTour = val; }

        /* cette methode renvoit la case sur laquelle le joueur veut jouer
            elle est abstraite puisqu'un humain choisira cette case a la main alors
            qu'une machine la choisira avec une fonction*/
        virtual Coordonnees choisirCase(Plateau* plateau);

    protected:
    private:
        string nom;
        char symbole;
        int numeroTour;
};

#endif // JOUEUR_H
