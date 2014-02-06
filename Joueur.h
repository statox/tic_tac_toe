#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;

class Joueur
{
    public:
        Joueur();
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        char Getsymbole() { return symbole; }
        void Setsymbole(char val) { symbole = val; }
    protected:
    private:
        string nom;
        char symbole;
};

#endif // JOUEUR_H
