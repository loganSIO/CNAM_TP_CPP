#include "Morpionx.h"
#include "Jeu.h"

//Constructeur

Morpionx morpionx(3, 3); 

//Fonction permettant la mise en marche d'une partie de morpion
void Morpionx::jeuDuMorpionx()
{
    Grille::initialiserGrille();

    while (!Jeu::gagnerDiagonale() && !Jeu::gagnerLigne() && !Jeu::gagnerColonne() && !Jeu::videGrille()) {
        std::cout << "Tour joueur 1" << endl;
        Jeu::demandeSaisieMorpion(1);
        if (!Jeu::gagnerDiagonale() && !Jeu::gagnerLigne() && !Jeu::gagnerColonne() && !Jeu::videGrille()) {
            std::cout << "Tour joueur 2" << endl;
            Jeu::demandeSaisieMorpion(2);
        }
    }

    if (Jeu::gagnerDiagonale() || Jeu::gagnerLigne() || Jeu::gagnerColonne())
    {
        std::cout << "Le gagnant est le " << Grille::j1OuJ2() << endl;
    }

    if (Jeu::videGrille() && !Jeu::gagnerDiagonale() && !Jeu::gagnerLigne() && !Jeu::gagnerColonne())
    {
        std::cout << "Vous etes a egalite" << endl;
    }
}
