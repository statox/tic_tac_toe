#ifndef NOEUDMINMAX_H
#define NOEUDMINMAX_H

#include "Plateau.h"

class NoeudMinMax
{
    public:
        NoeudMinMax(const Plateau&);
        virtual ~NoeudMinMax();
        Plateau* Getplateau() { return plateau; }
        void Setplateau(Plateau* val) { plateau = val; }
        int Getprofondeur() { return profondeur; }
        void Setprofondeur(int val) { profondeur = val; }

    private:
        Plateau* plateau;
        int profondeur;
};

#endif // NOEUDMINMAX_H
