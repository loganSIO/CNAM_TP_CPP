#include <iostream>
#include "Grille.h"
#include "Jeu.h"
#include "Morpionx.h"
#include "Puissance4.h"
#include "Othello.h"
using namespace std;

int main()
{
    int choix = 0;

    do
    {
        Morpionx jeu1 = Morpionx(3, 3);
        Puissance4 jeu2 = Puissance4(4, 7);
        Othello jeu3 = Othello(8, 8);

        std::cout << "-- Acces aux jeux --" << std::endl;
        std::cout << "1 - Morpion" << std::endl;
        std::cout << "2 - Puissance 4" << std::endl;
        std::cout << "3 - Othello" << std::endl;

        // Vérification si choice est un int 
        while (true)
        {
            std::cin >> choix;
            if (!std::cin)
            {
                std::cout << "Veuillez saisir un nombre entier." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else break;
        }

        switch (choix)
        {
        case 1:
            jeu1.jeuDuMorpionx();
            break;
        case 2:
            jeu2.jeuPuissance4();
            break;
        case 3:
            jeu3.jeuOthello();
            break;
        default:
            std::cout << "Veuillez choisir entre 1, 2 ou 3 !" << std::endl;
        }
    } while (choix > 3);

    return 0;
}