#ifndef COORDONNEES_H
#define COORDONNEES_H


class Coordonnees
{
    public:
        Coordonnees();
        virtual ~Coordonnees();
        int Getx() { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }
    protected:
    private:
        int x;
        int y;
};

#endif // COORDONNEES_H
