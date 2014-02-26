#include "Machine.h"
#include "Plateau.h"

#include "Humain.h"

#include "templates.h"
#include <stdlib.h>
#include <time.h>

Machine::Machine(string nom, char symbole) : Joueur(nom, symbole)
{
//    int niv;
//    cout << "saisissez le niveau de force de la machine: ";
//    cin >> niv;
//
//    Setniveau(niv);
//
//    int type;
//    cout << "saisissez le type d'IA de la machine: ";
//    cin >> type;
//
//    Setniveau(niv);
//    SettypeIA(type);
    if (nom=="aleat"){
        Setniveau(0);
        SettypeIA(0);
    }
    else{
        Setniveau(3);
        SettypeIA(1);
    }

}

Coordonnees Machine::choisirCase(Plateau* plateau)
{

    if(GettypeIA()==0){
        Coordonnees c = choixAleatoire(plateau);
        cout << "Je choisi au hasard: " << c << endl;
        return c;
    }
    else{
        Coordonnees* c = new Coordonnees(1,1);

        NoeudMinMax::cptNoeud = 0;
        NoeudMinMax n (*plateau, niveau, true);
        choixMinMax(n, c);

        cout << "j'ai choisi la case " << *c << endl;
        return *c;
    }
}

Coordonnees Machine::choixAleatoire(Plateau* plateau)
{
    Coordonnees c;
    srand(time(NULL));
    int col, lig;

    do{
        col = rand()%(plateau->GetnbColonnes());
        lig = rand()%(plateau->GetnbLignes());

        c.Setcol(col);
        c.Setlig(lig);
    }while(plateau->Getcase(c)!=0);

    return c;
}

int Machine::choixMinMax(NoeudMinMax n, Coordonnees* c_choisi)
{

    // si on a atteint la profondeur limité ou qu'on est en position fin de partie, on arrete la recursivité
    if (n.Getprofondeur()==0 || n.Getplateau()->masquePlein()!=0 || n.Getplateau()->estPlein()){
        return n.Getplateau()->evaluation();
    }

    //recherche des cases vides
    Plateau* p = n.Getplateau();
    vector <Coordonnees> casesVides;
    Coordonnees tmp;
    for (std::size_t col=0; col<p->GetnbColonnes(); col++){
        for (std::size_t lig=0; lig<p->GetnbLignes(); lig++){
            tmp.Setcol(col);
            tmp.Setlig(lig);
            if (p->Getcase(tmp)==0)
                casesVides.push_back(tmp);
        }
    }

    vector <int> resultatsMinMax;
    Plateau* pTmp;
    int val=1;
    if (n.GetestMax())
        val=-1;
    NoeudMinMax* nSucc;

    // pour toutes les cases vides
    for (std::size_t i=0; i<casesVides.size(); ++i){
        pTmp = new Plateau(*p);
        pTmp->Setcase(casesVides[i], val);

        nSucc = new NoeudMinMax (*pTmp, n.Getprofondeur()-1, !n.GetestMax());
        resultatsMinMax.push_back(choixMinMax(*nSucc, c_choisi));

    }

    int index=0;
    if (!n.GetestMax()){
        index = indexMaxi(resultatsMinMax);
        c_choisi->Setcol(casesVides[index].Getcol());
        c_choisi->Setlig(casesVides[index].Getlig());

        return maxi(resultatsMinMax);
    }else{
        index = indexMini(resultatsMinMax);
        c_choisi->Setcol(casesVides[index].Getcol());
        c_choisi->Setlig(casesVides[index].Getlig());

        return mini(resultatsMinMax);
    }
}

