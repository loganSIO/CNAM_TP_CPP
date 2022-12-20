#include "Morpionx.h"

//Constructeur

Morpionx::Morpionx(): Grille(3,3)
{

}

//Fonction permettant la mise en marche d'une partie de morpion
void Morpionx::jeuDuMorpionx()
{
    initialiserGrille();

    while (!gagnerDiagonale() && !gagnerLigne() && !gagnerColonne() && !videGrille()) {
        std::cout << "Tour joueur 1" << endl;
        Grille::demandeSaisie(1);
        if (!gagnerDiagonale() && !gagnerLigne() && !gagnerColonne() && !videGrille()) {
            std::cout << "Tour joueur 2" << endl;
            Grille::demandeSaisie(2);
        }
    }

    if (gagnerDiagonale() || gagnerLigne() || gagnerColonne())
    {
        std::cout << "Le gagnant est le " << j1OuJ2() << endl;
    }

    if (videGrille() && !gagnerDiagonale() && !gagnerLigne() && !gagnerColonne())
    {
        std::cout << "Vous etes a egalite" << endl;
    }
}

//Fonction permettant de verifier si un des joueurs à gagner (colonne)
bool Morpionx::gagnerColonne()
{
    // boucle sur toutes les colonnes
    for (int i = 0; i < 3; i++)
    {
        // check si toutes les vaeurs sont les mêmes
        if ((grille[0][i] == grille[1][i]) && (grille[1][i] == grille[2][i]) &&
            (grille[2][i] == grille[0][i]) && (grille[0][i] != 0) &&
            (grille[1][i] != 0) && (grille[2][i] != 0))
        {
            return true;
        }
    }

    return false;
}



//Fonction permettant de verifier si un des joueurs à gagner (diagonale)
bool Morpionx::gagnerDiagonale()
{
    // boucle pour les diagonales
    for (int i = 0; i < 2; i++)
    {
        int j = (i == 0) ? 0 : 2; // met j à 0 pour la première diagonale, 2 pour la seonde

        // check si toutes les valeurs des diagonales sont les mêmes
        if ((grille[0][j] == grille[1][1]) && (grille[1][1] == grille[2][2 - j]) &&
            (grille[2][2 - j] == grille[0][j]) && (grille[0][j] != 0) &&
            (grille[1][1] != 0) && (grille[2][2 - j] != 0))
        {
            return true;
        }
    }
        
    return false;
}


//Fonction permettant de verifier si un des joueurs à gagner (ligne)
bool Morpionx::gagnerLigne()
{
    // boucle sur les lignes
    for (int i = 0; i < 3; i++)
    {
        if ((grille[i][0] == grille[i][1]) && (grille[i][1] == grille[i][2]) &&
            (grille[i][2] == grille[i][0]) && (grille[i][0] != 0) &&
            (grille[i][1] != 0) && (grille[i][2] != 0))
        {
            return true;
        }
    }

    return false;
}
