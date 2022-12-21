#include "Othello.h"

//Constructeur

Othello::Othello() : Grille(8, 8)
{

}

//Fonction permettant la mise en marche d'une partie d'Othello
void Othello::jeuOthello()
{
    initialiserGrille();

    //Placement des pions initiaux (1 = blanc / 2 = noir)
    grille[3][3] = 1;
    grille[4][4] = 1;
    grille[3][4] = 2;
    grille[4][3] = 2;

    afficheGrille();

    while (!videGrille() && !gagneZero()) {
        std::cout << "Tour joueur 1" << endl;
        Othello::demandeSaisieMorpionOthello(1);
        if (!videGrille() && !gagneZero()) {
            std::cout << "Tour joueur 2" << endl;
            Othello::demandeSaisieMorpionOthello(2);
        }
    }

    int points_joueur_1 = 0;
    int points_joueur_2 = 0;

    // Calcul du nombre de pions de chaque joueurs à la fin de la partie
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grille[i][j] == 1) {
                points_joueur_1++;
            }
            else if (grille[i][j] == 2) {
                points_joueur_2++;
            }
        }
    }

    // Affichage des scores

    std::cout << "Joueur 1: " << points_joueur_1 << " pions" << endl;
    std::cout << "Joueur 2: " << points_joueur_2 << " pions" << endl;

    if (points_joueur_1 > points_joueur_2) {
        std::cout << "Joueur 1 a gagne !" << endl;
    }
    else if (points_joueur_1 == points_joueur_2) {
        std::cout << "Egalite !" << endl;
    }
    else {
        std::cout << "Joueur 2 a gagne !" << endl;
    }
}