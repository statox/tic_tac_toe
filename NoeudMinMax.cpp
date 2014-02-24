#include "NoeudMinMax.h"

NoeudMinMax::NoeudMinMax(const Plateau& p)
{
    plateau = new Plateau(p);
}

NoeudMinMax::~NoeudMinMax()
{
    plateau->~Plateau();
}
