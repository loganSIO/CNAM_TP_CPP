#include "Puissance4.h"
#include "Jeu.h"

//Constructeur

Puissance4 puissance4(4, 7);

//Fonction permettant la mise en marche d'une partie de puissance 4
void Puissance4::jeuPuissance4()
{
    Grille::initialiserGrille();

    while (!Jeu::gagnerDiagonalePuissance() && !Jeu::gagnerLignePuissance() && !Jeu::gagnerColonnePuissance() && !Grille::videGrille()) {
        std::cout << "Tour joueur 1" << endl;
        Jeu::demandeSaisiePuissance4(1);
        if (!Jeu::gagnerDiagonalePuissance() && !Jeu::gagnerLignePuissance() && !Jeu::gagnerColonnePuissance() && !Grille::videGrille()) {
            std::cout << "Tour joueur 2" << endl;
            Jeu::demandeSaisiePuissance4(2);
        }
    }

    if (Jeu::gagnerDiagonalePuissance() || Jeu::gagnerLignePuissance() || Jeu::gagnerColonnePuissance())
    {
        std::cout << "Le gagnant est le " << Grille::j1OuJ2() << endl;
    }

    if (Grille::videGrille() && !Jeu::gagnerDiagonalePuissance() && !Jeu::gagnerLignePuissance() && !Jeu::gagnerColonnePuissance())
    {
        std::cout << "Vous etes a egalite" << endl;
    }
}
