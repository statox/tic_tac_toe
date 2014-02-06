#ifndef PLATEAU_H
#define PLATEAU_H


class Plateau
{
    public:
        Plateau();
        int** Getplateau() { return plateau; }
        void Setplateau(int** val) { plateau = val; }
        int GettailleX() { return tailleX; }
        void SettailleX(int val) { tailleX = val; }
        int GettailleY() { return tailleY; }
        void SettailleY(int val) { tailleY = val; }
        int GetnbAlign() { return nbAlign; }
        void SetnbAlign(int val) { nbAlign = val; }
    protected:
    private:
        int** plateau;
        int tailleX;
        int tailleY;
        int nbAlign;
};

#endif // PLATEAU_H
