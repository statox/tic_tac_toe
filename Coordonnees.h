#ifndef COORDONNEES_H
#define COORDONNEES_H

#include <iostream>
using namespace std;

class Coordonnees
{
    public:
        Coordonnees();
        Coordonnees(int c, int l);
        int Getcol() { return col; }
        void Setcol(int val) { col = val; }
        int Getlig() { return lig; }
        void Setlig(int val) { lig = val; }

        friend ostream& operator<<(ostream&, const Coordonnees &c);
        friend bool operator==(const Coordonnees &c1, const Coordonnees &c2);
        friend bool operator<(const Coordonnees &c1, const Coordonnees &c2);

    protected:
    private:
        int col;
        int lig;
};

#endif // COORDONNEES_H
