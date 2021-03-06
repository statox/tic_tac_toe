#include "Plateau.h"
#include "Joueur.h"

#include "templates.h"
#include <fstream>

using namespace std;

Plateau::Plateau(int col, int lig, int align)
{

    // initialisation variables du plateau
    SetnbColonnes(col);
    SetnbLignes(lig);
    SetnbAlign(align);

    // reservation du plateau
    plateau = new int* [nbLignes];
    int i;
    for (i=0; i<nbLignes; i++)
        plateau[i] = new int [nbColonnes];

    // initialisation du plateau
    for (int i=0; i < nbLignes; i++)
        for (int j=0; j < nbColonnes; j++)
            plateau[i][j] = 0;

    // creation des masques du plateau
    creerMasques();
}

Plateau::Plateau(const Plateau& p)
{
    nbColonnes=p.nbColonnes;
    nbLignes=p.nbLignes;
    nbAlign=p.nbAlign;

    // reservation du plateau
    plateau = new int* [nbLignes];
    int i;
    for (i=0; i<nbLignes; i++)
        plateau[i] = new int [nbColonnes];

    // initialisation du plateau
    for (int i=0; i < nbLignes; i++)
        for (int j=0; j < nbColonnes; j++)
            plateau[i][j] = p.plateau[i][j];

    // creation des masques du plateau
    vector< vector<Coordonnees> > tmp = p.masques;
    for (std::size_t i=0; i<tmp.size(); ++i)
        masques.push_back(tmp[i]);

//    show(masques);
}

Plateau::Plateau(string chemin)
{
    //chargement du fichier contenant le plateau
    ifstream source (chemin.c_str());

    int col=-1, lig=0;
    int tmp;

    // initialisation variables du plateau
    source >> tmp;
    SetnbColonnes(tmp);
    source >> tmp;
    SetnbLignes(tmp);
    source >> tmp;
    SetnbAlign(tmp);

    // reservation du plateau
    plateau = new int* [nbLignes];
    int i;
    for (i=0; i<nbLignes; i++)
        plateau[i] = new int [nbColonnes];

    // initialisation du plateau
    for (int i=0; i < nbLignes; i++)
        for (int j=0; j < nbColonnes; j++)
            plateau[i][j] = 0;

    // creation des masques du plateau
    creerMasques();

    // recuperation des valeurs depuis le fichier
    Coordonnees c;
    bool continuer=true;
    while(continuer){
        source >> tmp;
        col++;
        if (col==nbColonnes-1 && lig==nbLignes-1)
            continuer=false;

        if(col==nbColonnes){
            col=0;
            lig++;
        }
        c.Setcol(col);
        c.Setlig(lig);

//        cout << c << " " << tmp << endl;

        Setcase(c, tmp);
    }
}

Plateau::~Plateau()
{
    for (std::size_t i=0; i<masques.size(); i++){
        masques[i].clear();
    }
    masques.clear();

    for (int i=0; i<nbLignes; i++)
        delete[] plateau[i];

    delete[] plateau;
}

void Plateau::afficher(Joueur* j1, Joueur* j2)
{
    for (int i=0; i < nbLignes; i++){
        for (int j=0; j < nbColonnes; j++){
            if (plateau[i][j]==j1->GetnumeroTour())
                cout << j1->Getsymbole() << " ";
            else if (plateau[i][j]==j2->GetnumeroTour())
                cout << j2->Getsymbole() << " ";
            else
                cout << "." << " ";
        }
        cout << endl;
    }
}

void Plateau::marquer(Coordonnees c, Joueur* j){

    if (Getcase(c)==0 /*&& c est dans le plateau*/){
        plateau[c.Getlig()][c.Getcol()] = j->GetnumeroTour();
    }
    else
    {
        cout << "case invalide echec du tour" << endl;
    }
}

void Plateau::creerMasques()
{
    vector<Coordonnees> tmp;    // tmp sera le vecteur temporaire qui servira a remplir masques

    masques.clear();

    /*  creation des masques correspondants aux lignes  */
    // pour chaque ligne
    for (int lig=0; lig<nbLignes; lig++){
        // pour chaque case de la ligne (jusqu'a la p-i�me avant la fin de la ligne)
        for (int col=0; col<nbColonnes-nbAlign+1; col++){
            tmp.clear();
            Coordonnees c(col-1,lig);
            // on ajoute au vecteur tmp p cases
            for (int k=0; k<nbAlign; k++){
                c.Setcol(c.Getcol()+1);
                tmp.push_back(c);
            }

            // on ajoute le nouveau masque a la collection
            masques.push_back(tmp);
        }
    }

    /*  creation des masques correspondants aux colonnes */
    // pour chaque colonne
    for (int col=0; col<nbColonnes; col++){
        // pour chaque case de la colonne (jusqu'a la p-ieme avant la fin de la colonne)
        for (int lig=0; lig<nbLignes-nbAlign+1; lig++){
            tmp.clear();
            Coordonnees c(col, lig-1);
            // on ajoute au vecteur tmp p cases
            for (int k=0; k<nbAlign; k++){
                c.Setlig(c.Getlig()+1);
                tmp.push_back(c);
            }

            // on ajoute le nouveau masque a la collection
            masques.push_back(tmp);
        }
    }

    /*  creation des masques correspondants aux diagonales \ */
    // pour chaque colonne (jusqu'a la p-ieme avant la fin du plateau)
    for (int col=0; col<nbColonnes-nbAlign+1; col++){
        // pour chaque ligne (jusqu'a la p-ieme apres le debut du plateau)
        for (int lig=0; lig<nbLignes-nbAlign+1; lig++){
            tmp.clear();
            Coordonnees c(col-1, lig-1);
            // on ajoute p cases au vecteur tmp
            for (int k=0; k<nbAlign; k++){
                c.Setlig(c.Getlig()+1);
                c.Setcol(c.Getcol()+1);
                tmp.push_back(c);
            }

            // on ajoute le nouveau masque a la collection
            masques.push_back(tmp);
        }
    }

    /* creation des masques correspondants aux diagonales / */
    // pour chaque colonne (jusqu'a la p-ieme avant la fin du plateau)
    for (int col=0; col<nbColonnes-nbAlign+1; col++){
        // pour chaque ligne (a partir de la p-ieme apres le debut du plateau)
        for (int lig=nbAlign-1; lig<nbLignes; lig++){
            tmp.clear();
            Coordonnees c(col-1, lig+1);
            // on ajoute p cases au vecteur tmp
            for (int k=0; k<nbAlign; k++){
                c.Setlig(c.Getlig()-1);
                c.Setcol(c.Getcol()+1);
                tmp.push_back(c);
            }

            // on ajoute le nouveau masque a la collection
            masques.push_back(tmp);
        }
    }

    /* elimination des eventuels doublons */
    // (en soit on a des doublons que dans le cas o� on a des masques de 1 cases mais on l'a impl�ment�, �a tourne qu'une fois a la cr�ation du plateau
    // donc autant le laisser ca fait pas de mal)
    removeDuplicates(masques);

    /* affichage de l'ensemble des masques (a desactiver dans la version finale) */
//    show(masques);
}


int Plateau::masquePlein()
{
    // on parcours tous les masques
    for (std::size_t i = 0; i < masques.size(); ++i){
        // si la premiere case du masque n'est pas un zero
        int premiereCase=Getcase(masques[i][0]);
        bool estEgal;
        if(premiereCase!=0){
            // on compare toutes les autres cases a la premiere
            std::size_t j=1;
            estEgal = true;
            while(j < masques[i].size() && estEgal){
                // si elle sont egale on continu a a parcourir le masque
                if(Getcase(masques[i][j])==premiereCase){
                    j++;
                // sinon on arrete et on passe au masque suivant
                }else{
                    estEgal=false;
                }
            }
        }
        // si on a parcouru tout le masque et que toutes les cases sont egales on renvoit leur valeur
        if(estEgal)
            return premiereCase;
    }
    // si on a parcouru tous les masques et qu'aucun n'est rempli on renvoit 0
    return 0;
}

bool Plateau::estPlein()
{
    bool casevide=false;
    for (int col=0; col<GetnbColonnes(); col++){
        for (int lig=0; lig<GetnbLignes(); lig++){
            if (Getcase(Coordonnees(col, lig))==0)
                casevide=true;
        }
    }
    return !casevide;
}


int Plateau::evaluation()
{
    int j1=0, j2=0;
    bool containsj1, containsj2;
    // on parcours tous les masques
    for (std::size_t i = 0; i < masques.size(); ++i){
        containsj1 = containsj2 = false;
        // on cherche si le masque contient un 1 (et un -1 au passage)
        std::size_t j=0;
        while(j<masques[i].size() && !containsj1){
            if(Getcase(masques[i][j])==1)
                containsj1=true;
            if (Getcase(masques[i][j])==-1)
                containsj2=true;
            j++;
        }
        // si on a pas trouv� de -1 on en recherche 1
        if(!containsj2 && j<masques[i].size()){
            while(j<masques[i].size() && !containsj2){
                if (Getcase(masques[i][j])==-1)
                    containsj2=true;
                j++;
            }
        }

        // si l'alignement n'est favorable qu'au j1 on incr�mente j1
        if (containsj1 && !containsj2)
            j1++;
        // si l'alignement n'est favorable qu'au j2 on incr�mente j2
        else if (!containsj1 && containsj2)
            j2++;
        // on pourrait ajouter dans les deux quand l'alignement est vide mais je vois pas l'interet

//          affichage pour les tests
//        show(masques[i]);
//        if (containsj1){
//            cout << "  j1";
//        }
//        else{
//            cout << "    ";
//        }
//        if (containsj2){
//            cout << "  j2";
//        }
//        cout << endl;
    }
//    cout << endl << endl << "j1: " << j1 << "  j2: " << j2 << endl;

    return j1-j2;
}
