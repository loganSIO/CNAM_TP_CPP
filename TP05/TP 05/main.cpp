#include <iostream>
#include "Grille.h"
#include "Morpionx.h"
#include "Puissance4.h"
#include "Othello.h"
using namespace std;

int main()
{
    int choice = 0;

    do
    {
        Morpionx game1 = Morpionx();
        Puissance4 game2 = Puissance4();
        Othello game3 = Othello();

        std::cout << "-- Acces aux jeux --" << std::endl;
        std::cout << "1 - Morpion" << std::endl;
        std::cout << "2 - Puissance 4" << std::endl;
        std::cout << "3 - Othello" << std::endl;

        // Vérification si choice est un int 
        while (true)
        {
            std::cin >> choice;
            if (!std::cin)
            {
                std::cout << "Veuillez saisir un nombre entier." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else break;
        }

        switch (choice)
        {
        case 1:
            game1.jeuDuMorpionx();
            break;
        case 2:
            game2.jeuPuissance4();
            break;
        case 3:
            game3.jeuOthello();
            break;
        default:
            std::cout << "Veuillez choisir entre 1, 2 ou 3 !" << std::endl;
        }
    } while (choice > 3);

    return 0;
}