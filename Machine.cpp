#include "Machine.h"
#include "Plateau.h"

#include "Humain.h"

#include "templates.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

Machine::Machine(string nom, char symbole, int type, int force) : Joueur(nom, symbole)
{
    // IA aleatoire
    if (type==0){
        Setniveau(0);
        SettypeIA(0);
    }
    // IA minmax sans elagage
    else if (type==1){
        Setniveau(force);
        SettypeIA(1);
    }
    // IA minmax avec elagage
    else{
        Setniveau(force);
        SettypeIA(2);
    }

}

Machine::Machine(string nom, char symbole) : Joueur(nom, symbole)
{
    int type;
    cout << "saisissez le type d'IA de la machine: " << endl;
    cout << "\t0. aleatoire" << endl << "\t1. minmax" << endl << "\t2. minmax avec elagage alpha beta" << endl;
    cin >> type;

    SettypeIA(type);
    Setniveau(0);

    if (type!=0){
        int niv;
        cout << "saisissez le niveau de force de la machine: ";
        cin >> niv;

        Setniveau(niv);
    }
}

Coordonnees Machine::choisirCase(Plateau* plateau)
{

    // choix aleatoire
    if(GettypeIA()==0){
        Coordonnees c = choixAleatoire(plateau);
        cout << "Je choisi au hasard: " << c << endl;
        return c;
    }
    // choix minmax
    else if (GettypeIA()==1 || GettypeIA()==2){

        Coordonnees* c = new Coordonnees(1,1);

        NoeudMinMax::cptNoeud = 0;
        int tempsAnalyse=time(NULL);
        NoeudMinMax n (*plateau, niveau, true);

        // sans elagage
        if (GettypeIA()==1){
            choixMinMax(n, c);
        // avec elagage
        }else{
            choixMinMaxElagage(n, c, -INFINI, INFINI);
        }

        tempsAnalyse = time(NULL) - tempsAnalyse;
        cout << "analyse: \t" << NoeudMinMax::cptNoeud << " \tnoeuds en " << tempsAnalyse << " s" << endl;
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

        pTmp->~Plateau();
        resultatsMinMax.push_back(choixMinMax(*nSucc, c_choisi));

    }

    int index=0;
    int valreturn=0;
    if (!n.GetestMax()){
        index = indexMaxi(resultatsMinMax);
        c_choisi->Setcol(casesVides[index].Getcol());
        c_choisi->Setlig(casesVides[index].Getlig());
        valreturn = maxi(resultatsMinMax);

        n.~NoeudMinMax();
        return valreturn;
    }else{
        index = indexMini(resultatsMinMax);
        c_choisi->Setcol(casesVides[index].Getcol());
        c_choisi->Setlig(casesVides[index].Getlig());
        valreturn = mini(resultatsMinMax);

        n.~NoeudMinMax();
        return valreturn;
    }
}

int Machine::choixMinMaxElagage(NoeudMinMax n, Coordonnees* c_choisi, int alpha, int beta)
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

    // si on a un noeud min
    if (!n.GetestMax()){
        int valeur = INFINI;
        //pout tous les fils du noeud
        for (std::size_t i=0; i<casesVides.size(); ++i){
            pTmp = new Plateau(*p);
            pTmp->Setcase(casesVides[i], val);
            nSucc = new NoeudMinMax (*pTmp, n.Getprofondeur()-1, !n.GetestMax());

            valeur = min (valeur, choixMinMaxElagage(*nSucc, c_choisi, alpha, beta));
            pTmp->~Plateau();

        c_choisi->Setcol(casesVides[i].Getcol());
        c_choisi->Setlig(casesVides[i].Getlig());

            if (alpha>=valeur)  //coupure alpha
                return valeur;

            beta = min (beta, val);
        }
    }else{
        int valeur = -INFINI;
        // pour tous les fils du noeud
        for (std::size_t i=0; i<casesVides.size(); ++i){
            pTmp = new Plateau(*p);
            pTmp->Setcase(casesVides[i], val);
            nSucc = new NoeudMinMax (*pTmp, n.Getprofondeur()-1, !n.GetestMax());

            valeur = max (valeur, choixMinMaxElagage(*nSucc, c_choisi, alpha, beta));
            pTmp->~Plateau();

        c_choisi->Setcol(casesVides[i].Getcol());
        c_choisi->Setlig(casesVides[i].Getlig());

            if (valeur>=beta)  //coupure beta
                return valeur;

            alpha = max (alpha, val);
        }
    }



//    int index=0;
//    int valreturn=0;
//    if (!n.GetestMax()){
//        index = indexMaxi(resultatsMinMax);
//        c_choisi->Setcol(casesVides[index].Getcol());
//        c_choisi->Setlig(casesVides[index].Getlig());
//        valreturn = maxi(resultatsMinMax);
//
//        n.~NoeudMinMax();
//        return valreturn;
//    }else{
//        index = indexMini(resultatsMinMax);
//        c_choisi->Setcol(casesVides[index].Getcol());
//        c_choisi->Setlig(casesVides[index].Getlig());
//        valreturn = mini(resultatsMinMax);
//
//        n.~NoeudMinMax();
//        return valreturn;
//    }
}
