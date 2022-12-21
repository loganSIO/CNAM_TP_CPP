#include "Morpionx.h"

//Constructeur

Morpionx::Morpionx() : Grille(3, 3)
{

}

//Fonction permettant la mise en marche d'une partie de morpion
void Morpionx::jeuDuMorpionx()
{
    initialiserGrille();

    while (!gagnerDiagonale() && !gagnerLigne() && !gagnerColonne() && !videGrille()) {
        std::cout << "Tour joueur 1" << endl;
        Grille::demandeSaisieMorpion(1);
        if (!gagnerDiagonale() && !gagnerLigne() && !gagnerColonne() && !videGrille()) {
            std::cout << "Tour joueur 2" << endl;
            Grille::demandeSaisieMorpion(2);
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
