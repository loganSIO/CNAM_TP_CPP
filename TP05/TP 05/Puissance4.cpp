#include "Puissance4.h"

//Constructeur

Puissance4::Puissance4() : Grille(4, 7)
{

}

//Fonction permettant la mise en marche d'une partie de puissance 4
void Puissance4::jeuPuissance4()
{
    initialiserGrille();

    while (!gagnerDiagonalePuissance() && !gagnerLignePuissance() && !gagnerColonnePuissance() && !videGrille()) {
        std::cout << "Tour joueur 1" << endl;
        Grille::demandeSaisiePuissance4(1);
        if (!gagnerDiagonalePuissance() && !gagnerLignePuissance() && !gagnerColonnePuissance() && !videGrille()) {
            std::cout << "Tour joueur 2" << endl;
            Grille::demandeSaisiePuissance4(2);
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
