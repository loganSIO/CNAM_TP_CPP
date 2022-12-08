#include "Puissance4.h"

//Constructeur

Puissance4::Puissance4(): Grille(4,7)
{

}

//Fonction permettant la mise en marche d'une partie de puissance 4
void Puissance4::jeuPuissance4()
{
    initialiserGrille();

    while (!gagnerDiagonalePuissance() && !gagnerLignePuissance() && !gagnerColonnePuissance() && !videGrille()) {
        std::cout << "Tour joueur 1" << endl;
        Grille::demandeSaisieColonne(1);
        if (!gagnerDiagonalePuissance() && !gagnerLignePuissance() && !gagnerColonnePuissance() && !videGrille()) {
            std::cout << "Tour joueur 2" << endl;
            Grille::demandeSaisieColonne(2);
        }
    }

    if (gagnerDiagonalePuissance() || gagnerLignePuissance() || gagnerColonnePuissance())
    {
        std::cout << "Le gagnant est le " << j1OuJ2() << endl;
    }

    if (videGrille() && !gagnerDiagonalePuissance() && !gagnerLignePuissance() && !gagnerColonnePuissance())
    {
        std::cout << "Vous etes a egalite" << endl;
    }
}

//Permet de savoir si il y a une ligne gagnante puissance4
bool Puissance4::gagnerLignePuissance()
{
    // boucle sur les lignes
    for (int i = 0; i < 4; i++)
    {
        // Check s'il y a 4 même élément sur une même ligne > gagne
        for (int j = 0; j < 4; j++)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i][j + 1] && grille[i][j + 1] == grille[i][j + 2] && grille[i][j + 2] == grille[i][j + 3])
            {
                return true;
            }
        }
    }

    return false;
}


//Permet de savoir si il y a une colonne gagnante puissance4
bool Puissance4::gagnerColonnePuissance()
{
    // boucle sur les colonnes
    for (int i = 0; i < 4; i++)
    {
        // check s'il y a 4 fois le même joueur sur une colonne > gagne
        if ((grille[0][i] == grille[1][i]) && (grille[1][i] == grille[2][i]) &&
            (grille[2][i] == grille[0][i]) && (grille[3][i] == grille[0][i]) && (grille[0][i] != 0) &&
            (grille[1][i] != 0) && (grille[2][i] != 0) && (grille[3][i] != 0))
        {
            return true;
        }
    }

    return false;
}

bool Puissance4::gagnerDiagonalePuissance()
{
    // boucle sur les lignes
    for (int i = 0; i < 4; i++)
    {
        // boucle sur les colonnes
        for (int j = 0; j < 4; j++)
        {
            // check si les diagonales ont 4 mêmes consécutives
            if (grille[i][j] != 0 && i + 3 < 4 && j + 3 < 4 && grille[i][j] == grille[i + 1][j + 1] && grille[i + 1][j + 1] == grille[i + 2][j + 2] && grille[i + 2][j + 2] == grille[i + 3][j + 3])
            {
                return true;
            }

            if (grille[i][j] != 0 && i + 3 < 4 && j - 3 >= 0 && grille[i][j] == grille[i + 1][j - 1] && grille[i + 1][j - 1] == grille[i + 2][j - 2] && grille[i + 2][j - 2] == grille[i + 3][j - 3])
            {
                return true;
            }
        }
    }

    return false;
}
