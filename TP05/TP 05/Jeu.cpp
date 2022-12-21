#include "Jeu.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

// MORPIOOOOOOOOOOOOOOOOOOOOON

Jeu jeu();


//Fonction demande saisie joueur
void Jeu::demandeSaisieMorpion(int joueur_actuel)
{
    int saisieligne = 0;

    std::cout << "Le joueur indique dans quel colonne sera son pion" << std::endl;

    while (true)
    {
        std::cin >> saisieligne;
        if (!std::cin)
        {
            std::cout << "Veuillez saisir un nombre entier." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (saisieligne >= 0 && saisieligne < grille.size())
        {
            break;
        }
        else
        {
            std::cout << "Veuillez saisir un nombre entier compris entre 0 et " << grille.size() - 1 << "." << std::endl;
        }
    }

    int saisiecolonne = 0;

    std::cout << "Le joueur indique dans quel ligne sera son pion" << std::endl;

    while (true)
    {
        std::cin >> saisiecolonne;
        if (!std::cin)
        {
            std::cout << "Veuillez saisir un nombre entier." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (saisiecolonne >= 0 && saisiecolonne < grille[0].size())
        {
            break;
        }
        else
        {
            std::cout << "Veuillez saisir un nombre entier compris entre 0 et " << grille[0].size() - 1 << "." << std::endl;
        }
    }

    if (caseVide(saisiecolonne, saisieligne) && porteeGrille(saisiecolonne, saisieligne)) {
        insererPoint(saisiecolonne, saisieligne, joueur_actuel);
    }
    else
    {
        std::cout << "Erreur de saisie ou case rempli" << std::endl;
        demandeSaisieMorpion(joueur_actuel);
    }
}

//Fonction permettant de verifier si un des joueurs � gagner (colonne)
bool Jeu::gagnerColonne()
{
    // boucle sur toutes les colonnes
    for (int i = 0; i < 3; i++)
    {
        // check si toutes les vaeurs sont les m�mes
        if ((grille[0][i] == grille[1][i]) && (grille[1][i] == grille[2][i]) &&
            (grille[2][i] == grille[0][i]) && (grille[0][i] != 0) &&
            (grille[1][i] != 0) && (grille[2][i] != 0))
        {
            return true;
        }
    }

    return false;
}



//Fonction permettant de verifier si un des joueurs � gagner (diagonale)
bool Jeu::gagnerDiagonale()
{
    // boucle pour les diagonales
    for (int i = 0; i < 2; i++)
    {
        int j = (i == 0) ? 0 : 2; // met j � 0 pour la premi�re diagonale, 2 pour la seonde

        // check si toutes les valeurs des diagonales sont les m�mes
        if ((grille[0][j] == grille[1][1]) && (grille[1][1] == grille[2][2 - j]) &&
            (grille[2][2 - j] == grille[0][j]) && (grille[0][j] != 0) &&
            (grille[1][1] != 0) && (grille[2][2 - j] != 0))
        {
            return true;
        }
    }

    return false;
}


//Fonction permettant de verifier si un des joueurs � gagner (ligne)
bool Jeu::gagnerLigne()
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

// PUISSSSSSSSANNNNNNNNNNCE 4
// Demande de saisie pour colonne uniquement
bool Jeu::demandeSaisiePuissance4(int joueur_actuel)
{
    int saisiecolonne = 0;

    std::cout << "Le joueur indique dans quel colonne sera son pion" << std::endl;

    while (true)
    {
        std::cin >> saisiecolonne;
        if (!std::cin)
        {
            std::cout << "Veuillez saisir un nombre entier." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (saisiecolonne >= 0 && saisiecolonne < grille[0].size())
        {
            break;
        }
        else
        {
            std::cout << "Veuillez saisir un nombre entier compris entre 0 et " << grille[0].size() - 1 << "." << std::endl;
        }
    }

    // permet au pion de se situer tout en bas de la grille
    for (int i = 3; i >= 0; i--)
    {
        if (caseVide(i, saisiecolonne) && porteeGrille(i, saisiecolonne))
        {
            grille[i][saisiecolonne] = joueur_actuel;
            afficheGrille();
            return true;
        }
    }
    return false;
}

//Permet de savoir si il y a une ligne gagnante puissance4
bool Jeu::gagnerLignePuissance()
{
    // boucle sur les lignes
    for (int i = 0; i < 4; i++)
    {
        // Check s'il y a 4 m�me �l�ment sur une m�me ligne > gagne
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
bool Jeu::gagnerColonnePuissance()
{
    // boucle sur les colonnes
    for (int i = 0; i < 4; i++)
    {
        // check s'il y a 4 fois le m�me joueur sur une colonne > gagne
        if ((grille[0][i] == grille[1][i]) && (grille[1][i] == grille[2][i]) &&
            (grille[2][i] == grille[0][i]) && (grille[3][i] == grille[0][i]) && (grille[0][i] != 0) &&
            (grille[1][i] != 0) && (grille[2][i] != 0) && (grille[3][i] != 0))
        {
            return true;
        }
    }

    return false;
}

bool Jeu::gagnerDiagonalePuissance()
{
    // boucle sur les lignes
    for (int i = 0; i < 4; i++)
    {
        // boucle sur les colonnes
        for (int j = 0; j < 4; j++)
        {
            // check si les diagonales ont 4 m�mes cons�cutives
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

// OTHELLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLO

bool Jeu::gagneZero()
{
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

    if (points_joueur_1 == 0 || points_joueur_2 == 0) {
        return true;
    }

    return false;
}

void Jeu::demandeSaisieMorpionOthello(int joueur_actuel)
{
    while (true) {
        int saisieligne = 0;
        int saisiecolonne = 0;
        while (true) {
            std::cout << "Le joueur indique dans quel colonne sera son pion" << std::endl;
            std::cin >> saisieligne;
            if (!std::cin) {
                std::cout << "Veuillez saisir un nombre entier." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else if (saisieligne >= 0 && saisieligne < grille.size()) {
                break;
            }
            else {
                std::cout << "Veuillez saisir un nombre entier compris entre 0 et " << grille.size() - 1 << "." << std::endl;
            }
        }
        while (true) {
            std::cout << "Le joueur indique dans quel ligne sera son pion" << std::endl;
            std::cin >> saisiecolonne;
            if (!std::cin) {
                std::cout << "Veuillez saisir un nombre entier." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else if (saisiecolonne >= 0 && saisiecolonne < grille[0].size()) {
                break;
            }
            else {
                std::cout << "Veuillez saisir un nombre entier compris entre 0 et " << grille[0].size() - 1 << "." << std::endl;
            }
        }
        // V�rifie si la position sp�cifi�e est vide et dans les limites de la grille.
        if (caseVide(saisiecolonne, saisieligne) && porteeGrille(saisiecolonne, saisieligne)) {
            // V�rifier si le placement d'un pion � la position sp�cifi�e entra�nera le retournement des pions ennemis.
            if (remplacerColonneOthello(saisiecolonne, saisieligne, joueur_actuel) ||
                remplacerLigneOthello(saisiecolonne, saisieligne, joueur_actuel) ||
                remplacerDiagonaleOthello(saisiecolonne, saisieligne, joueur_actuel)) {
                // Placez le pion si cela entra�ne le retournement d'au moins un pion ennemi.
                insererPoint(saisiecolonne, saisieligne, joueur_actuel);
                break;
            }
            else {
                std::cout << "Placement de pion non valide" << endl;
            }
        }
        else {
            std::cout << "Erreur de saisie ou case rempli" << endl;
        }
    }
}

bool Jeu::remplacerColonneOthello(int x, int y, int joueur_actuel)
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

bool Jeu::remplacerLigneOthello(int x, int y, int joueur_actuel)
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

bool Jeu::remplacerDiagonaleOthello(int x, int y, int joueur_actuel)
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
