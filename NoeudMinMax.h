#ifndef NOEUDMINMAX_H
#define NOEUDMINMAX_H

#include "Plateau.h"

class NoeudMinMax
{
    public:
        NoeudMinMax(const Plateau&, int, bool);
        virtual ~NoeudMinMax();
        Plateau* Getplateau() { return plateau; }
        void Setplateau(Plateau* val) { plateau = val; }
        int Getprofondeur() { return profondeur; }
        void Setprofondeur(int val) { profondeur = val; }
        bool GetestMax() { return estMax; }
        void SetestMax(bool val) { estMax = val; }
        void resetCptNoeud() {cptNoeud=0;};

        //cpt d'instance
        static int cptNoeud;

    private:
        Plateau* plateau;
        int profondeur;
        bool estMax;


};

#endif // NOEUDMINMAX_H
