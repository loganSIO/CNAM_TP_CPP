#include "Othello.h"

//Constructeur

Othello::Othello() : Grille(8, 8)
{

}

//Fonction permettant la mise en marche d'une partie d'Othello
void Othello::jeuOthello()
{
    int saisiecolonne = 0;
    int saisieligne = 0;
    int joueur_actuel = 0;

    initialiserGrille();

    //Placement des pions initiaux (1 = blanc / 2 = noir)
    grille[3][3] = 1;
    grille[4][4] = 1;
    grille[3][4] = 2;
    grille[4][3] = 2;

    afficheGrille();

    while (!videGrille()) {
        std::cout << "Tour joueur 1" << endl;
        Othello::demandeSaisieOthello(1);
        if (!videGrille()) {
            std::cout << "Tour joueur 2" << endl;
            Othello::demandeSaisieOthello(2);
        }
    }

    int points_joueur_1 = 0;
    int points_joueur_2 = 0;

    // Calcul du nombre de pions de chaque joueurs � la fin de la partie
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

    std::cout << "Joueur 1: " << points_joueur_1 << " points" << endl;
    std::cout << "Joueur 2: " << points_joueur_2 << " points" << endl;

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

bool Othello::remplacerColonneOthello(int x, int y, int joueur_actuel)
{
    bool renversement_pions = false;
    int pion_enemy = (joueur_actuel == 1) ? 2 : 1;  // le pion ennemi = l'inverse du joueur actuel

    // v�rification qu'un pion ennemi se trouve � une position sp�cifi� par l'input du joueur
    int i = y + 1;  // on commence par la ligne d'en-dessous de la case sp�cifi� 
    while (i < 8 && grille[x][i] == pion_enemy) {
        i++;
    }
    // S'il y a un pion ennemi dans la m�me colonne et un pion du joueur actuel imm�diatement apr�s, retournez les pions ennemis.
    if (i < 8 && grille[x][i] == joueur_actuel) {
        i = y + 1;
        while (grille[x][i] == pion_enemy) {
            grille[x][i] = joueur_actuel;
            i++;
            renversement_pions = true;
        }
    }

    // rep�tition avec les lignes du dessous
    i = y - 1; 
    while (i >= 0 && grille[x][i] == pion_enemy) {
        i--;
    }
    if (i >= 0 && grille[x][i] == joueur_actuel) {
        i = y - 1;
        while (grille[x][i] == pion_enemy) {
            grille[x][i] = joueur_actuel;
            i--;
            renversement_pions = true;
        }
    }

    return renversement_pions;
}

bool Othello::remplacerLigneOthello(int x, int y, int joueur_actuel)
{
    bool renversement_pions = false;
    int pion_enemy = (joueur_actuel == 1) ? 2 : 1;

    // Check s'il y a un pion ennemi dans la m�me rang�e que la position sp�cifi�e.
    int i = x + 1;  // commencer la recherche � partir de la colonne situ�e � droite de la position sp�cifi�e
    while (i < 8 && grille[i][y] == pion_enemy) {
        i++;
    }
    // S'il y a un pion ennemi dans la m�me rang�e et un pion du joueur actuel imm�diatement apr�s, retournez les pions ennemis.
    if (i < 8 && grille[i][y] == joueur_actuel) {
        i = x + 1;
        while (grille[i][y] == pion_enemy) {
            grille[i][y] = joueur_actuel;
            i++;
            renversement_pions = true;
        }
    }

    // R�p�tez le processus ci-dessus pour les colonnes situ�es � gauche de la position sp�cifi�e.
    i = x - 1;  // commence la recherche � partir de la colonne situ�e � gauche de la position sp�cifi�e
    while (i >= 0 && grille[i][y] == pion_enemy) {
        i--;
    }
    if (i >= 0 && grille[i][y] == joueur_actuel) {
        i = x - 1;
        while (grille[i][y] == pion_enemy) {
            grille[i][y] = joueur_actuel;
            i--;
            renversement_pions = true;
        }
    }

    return renversement_pions;
}

bool Othello::remplacerDiagonaleOthello(int x, int y, int joueur_actuel)
{
    bool renversement_pions = false;
    int pion_enemy = (joueur_actuel == 1) ? 2 : 1;

    // V�rifier la diagonale de haut en bas et de gauche � droite.
    int i = x - 1, j = y - 1;
    while (i >= 0 && j >= 0 && grille[i][j] == pion_enemy)
    {
        i--;
        j--;
    }
    if (i >= 0 && j >= 0 && grille[i][j] == joueur_actuel)
    {
        // Retourner les pions ennemis dans la diagonale de haut en bas et de gauche � droite.
        i++;
        j++;
        while (i < x && j < y)
        {
            grille[i][j] = joueur_actuel;
            i++;
            j++;
        }
        renversement_pions = true;
    }

    // V�rifier la diagonale du bas de la gauche vers le haut de la droite.
    i = x + 1, j = y - 1;
    while (i < 8 && j >= 0 && grille[i][j] == pion_enemy)
    {
        i++;
        j--;
    }
    if (i < 8 && j >= 0 && grille[i][j] == joueur_actuel)
    {
        // Retourner les pions ennemis dans la diagonale du bas � gauche et du haut � droite.
        i--;
        j++;
        while (i > x && j < y)
        {
            grille[i][j] = joueur_actuel;
            i--;
            j++;
        }
        renversement_pions = true;
    }

    return renversement_pions;
}

void Othello::demandeSaisieOthello(int joueur_actuel)
{
    int saisieligne = 0;
    int saisiecolonne = 0;

    std::cout << "Le joueur indique dans quel colonne sera son pion" << endl;
    std::cin >> saisieligne;
    std::cin.ignore();

    std::cout << "Le joueur indique dans quel ligne sera son pion" << endl;
    std::cin >> saisiecolonne;
    std::cin.ignore();

    // V�rifie si la position sp�cifi�e est vide et dans les limites de la grille.
    if (caseVide(saisiecolonne, saisieligne) && porteeGrille(saisiecolonne, saisieligne)) {
        // V�rifier si le placement d'un pion � la position sp�cifi�e entra�nera le retournement des pions ennemis.
        if (remplacerColonneOthello(saisiecolonne, saisieligne, joueur_actuel) ||
            remplacerLigneOthello(saisiecolonne, saisieligne, joueur_actuel) ||
            remplacerDiagonaleOthello(saisiecolonne, saisieligne, joueur_actuel)) {
            // Placez le pion si cela entra�ne le retournement d'au moins un pion ennemi.
            insererPoint(saisiecolonne, saisieligne, joueur_actuel);
        }
        else {
            std::cout << "Placement de pion non valide" << endl;
            demandeSaisie(joueur_actuel);
        }
    }
    else {
        std::cout << "Erreur de saisie ou case rempli" << endl;
        demandeSaisie(joueur_actuel);
    }
}
