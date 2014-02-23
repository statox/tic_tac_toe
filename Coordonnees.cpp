#include "Coordonnees.h"

Coordonnees::Coordonnees() : col(0), lig(0) { }
Coordonnees::Coordonnees(int c, int l) : col(c), lig(l) { }

ostream& operator<<(ostream& os, const Coordonnees &c)
{
    os << "(" << c.col << " , " << c.lig << ")";
    return os;
}
