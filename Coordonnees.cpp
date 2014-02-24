#include "Coordonnees.h"

Coordonnees::Coordonnees() : col(0), lig(0) { }
Coordonnees::Coordonnees(int c, int l) : col(c), lig(l) { }

ostream& operator<<(ostream& os, const Coordonnees &c)
{
    os << "(" << c.col << " , " << c.lig << ")";
    return os;
}

bool operator==(const Coordonnees &c1, const Coordonnees &c2)
{
    if (c1.col==c2.col && c1.lig==c2.lig)
        return true;

    return false;
}

bool operator<(const Coordonnees &c1, const Coordonnees &c2)
{
    if (c1.col<c2.col){
        return true;
    }else if (c1.col==c2.col){
        if (c1.lig<c2.lig){
            return true;
        }
    }
    return false;
}
