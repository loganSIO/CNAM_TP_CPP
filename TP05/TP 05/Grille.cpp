#include "Grille.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

//Constructeur
Grille::Grille(const int ColonneVector, const int LigneVector)
{
    colonnevector = ColonneVector;
    lignevector = LigneVector;
}

// Setter de lignevector
void Grille::setLignevector(const int lv)
{
    lignevector = lv;
}
//Getter de lignevector
int Grille::getLignevector() const
{
    return lignevector;
}

// Setter de colonnevector
void Grille::setColonnevector(const int cv)
{
    colonnevector = cv;
}
//Getter de colonnevector
int Grille::getColonnevector() const
{
    return colonnevector;
}

//Fonction permettant d'initialiser la grille
void Grille::initialiserGrille()
{
    int i;
    grille.resize(colonnevector);
    for (i = 0; i < colonnevector; i++)
    {
        grille[i].resize(lignevector, 0); // initialize all values to 0
    }
}

//Fonction permettant d'afficher la grille
void Grille::afficheGrille()
{
    for (int j = 0;j < colonnevector;j++)
    {
        std::cout << "[";
        for (int i = 0;i < lignevector;i++)
            std::cout << grille[j][i];
        std::cout << "]\n";
    }
}


//Fonction permettant de savoir si l'utilisateur n'a pas dépassé la portee de la grille
bool Grille::porteeGrille(const int saisieligne, const int saisiecolonne) const
{
    return (saisiecolonne >= 0) && (saisiecolonne < grille[0].size()) && (saisieligne >= 0) && (saisieligne < grille.size());
}

//Fonction permettant de savoir si la case selectionnée par l'utilisateur est vide
bool Grille::caseVide(const int saisiecolonne, const int saisieligne) const
{
    if (grille[saisiecolonne][saisieligne] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Fonction permettant d'ajouter le point du joueur
void Grille::insererPoint(int saisiecolonne, int saisieligne, int id)
{
    grille[saisiecolonne][saisieligne] = id;
    afficheGrille();
}


//Fonction permettant de savoir si le tableau est vide ou non (egalite)
//return true si il est vide
//return false si il est remplis
bool Grille::videGrille()
{
    int nb_occ = 0;

    for (int j = 0;j < colonnevector;j++)
    {
        for (int i = 0;i < lignevector;i++)
        {
            if (grille[j][i] == 0)
                nb_occ++;
        }
    }
    if (nb_occ != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Fonction permettant de savoir qui est le gagnant
string Grille::j1OuJ2()
{
    int nb_occ_1 = 0;

    for (int j = 0;j < colonnevector;j++)
    {
        for (int i = 0;i < lignevector;i++)
        {
            if (grille[j][i] == 1)
                nb_occ_1++;
        }
    }
    int nb_occ_2 = 0;
    for (int j = 0;j < colonnevector;j++)
    {
        for (int i = 0;i < lignevector;i++)
        {
            if (grille[j][i] == 2)
                nb_occ_2++;
        }
    }
    if (nb_occ_1 > nb_occ_2)
    {
        return "Joueur 1";
    }
    else
    {
        return "Joueur 2";
    }
}
