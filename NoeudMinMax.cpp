#include "NoeudMinMax.h"

int NoeudMinMax::cptNoeud = 0;

NoeudMinMax::NoeudMinMax(const Plateau& p, int prof, bool maxi)
{
    plateau = new Plateau(p);
    profondeur = prof;
    estMax = maxi;

    cptNoeud++;
}

NoeudMinMax::~NoeudMinMax()
{
//    cout << "destruction noeud profondeur " << profondeur << endl;
    plateau->~Plateau();
}
