#include "Othello.h"
#include "Jeu.h"

//Constructeur

Othello othello(8, 8);

//Fonction permettant la mise en marche d'une partie d'Othello
void Othello::jeuOthello()
{
    Grille::initialiserGrille();

    //Placement des pions initiaux (1 = blanc / 2 = noir)
    Grille::grille[3][3] = 1;
    Grille::grille[4][4] = 1;
    Grille::grille[3][4] = 2;
    Grille::grille[4][3] = 2;

    Grille::afficheGrille();

    while (!Grille::videGrille() && !Jeu::gagneZero()) {
        std::cout << "Tour joueur 1" << endl;
        Jeu::demandeSaisieOthello(1);
        if (!Grille::videGrille() && !Jeu::gagneZero()) {
            std::cout << "Tour joueur 2" << endl;
            Jeu::demandeSaisieOthello(2);
        }
    }

    int points_joueur_1 = 0;
    int points_joueur_2 = 0;

    // Calcul du nombre de pions de chaque joueurs à la fin de la partie
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (Grille::grille[i][j] == 1) {
                points_joueur_1++;
            }
            else if (Grille::grille[i][j] == 2) {
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