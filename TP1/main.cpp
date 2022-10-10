#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

#include "tennis.h"
#include "saisies.h"
#include "manip_nombres.h"


// I. Manipulation de nombres

void ManipulationNombres()
{
    int choice = 0;
    int a, b, c, tabSize, borne;

    do
    {
        std::cout << "-- Acces aux parties de l'exercice 1 --" << std::endl;
        std::cout << "1 - Somme de deux entiers" << std::endl;
        std::cout << "2 - Inversion de la valeur de deux entiers" << std::endl;
        std::cout << "3 - Somme des deux premiers entiers dans un troisieme entier avec pointeur" << std::endl;
        std::cout << "4 - Somme des deux premiers entiers dans un troisieme entier avec reference" << std::endl;
        std::cout << "5 - Tableau aleatoire et tri par ordre croissant" << std::endl;

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
            std::cout << "Entrez deux entiers separes par un espace " << std::endl;

            while (true)
            {
                std::cin >> a;
                std::cin >> b;

                if (!std::cin)
                {
                    std::cout << "Veuillez saisir un nombre entier." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else break;
            }

            std::cout << Somme(a, b) << std::endl;
            break;
        case 2:
            std::cout << "Entrez deux entiers separes par un espace " << std::endl;

            while (true)
            {
                std::cin >> a;
                std::cin >> b;

                if (!std::cin)
                {
                    std::cout << "Veuillez saisir un nombre entier." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else break;
            }

            Inverse(a, b);
            break;
        case 3:
            std::cout << "Entrez trois entiers separes par un espace " << std::endl;

            while (true)
            {
                std::cin >> a;
                std::cin >> b;
                std::cin >> c;

                if (!std::cin)
                {
                    std::cout << "Veuillez saisir un nombre entier." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else break;
            }

            std::cout << ReplacePointeur(a, b, c) << std::endl;
            break;
        case 4:
            std::cout << "Entrez trois entiers separes par un espace " << std::endl;

            while (true)
            {
                std::cin >> a;
                std::cin >> b;
                std::cin >> c;

                if (!std::cin)
                {
                    std::cout << "Veuillez saisir un nombre entier." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else break;
            }

            std::cout << ReplaceReference(a, b, c) << std::endl;
            break;
        case 5:
            int* tabRan;
            std::cout << "Taille du tableau : " << std::endl;

            while (true)
            {
                std::cin >> tabSize;

                if (!std::cin)
                {
                    std::cout << "Veuillez saisir un nombre entier." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else break;
            }

            std::cout << "Jusqu\'a quelle borne : " << std::endl;

            while (true)
            {
                std::cin >> borne;

                if (!std::cin)
                {
                    std::cout << "Veuillez saisir un nombre entier." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else break;
            }

            tabRan = new int[tabSize];
            TableauAleatoire(tabRan, tabSize, borne);
            break;
        default:
            std::cout << "Veuillez choisir entre 1, 2, 3, 4 ou 5 !" << std::endl;
        }
    } while (choice > 5);
}

// II. Tennis

void Tennis()
{
    // Initialisation d'un tableau de score à 0 0 
    int tabScore[] = { 0, 0 };

    // Affichage intial des scores (0;0)
    PrintScore(1, tabScore[0]);
    PrintScore(2, tabScore[1]);

    do {
        std::cout << "Affrontement entre Joueur 1 et Joueur 2" << std::endl;

        // Génère de façon aléatoire si le Joueur 1 ou le Joueur 2 gagne
        srand((unsigned int)time(NULL));
        int result = rand() % 2 + 1;

        CalculScore(result - 1, tabScore);

        std::this_thread::sleep_for(std::chrono::milliseconds(1500));

        // Affichage des scores après chaque points
        PrintScore(1, tabScore[0]);
        PrintScore(2, tabScore[1]);
    } while (tabScore[0] != VICTOIRE && tabScore[1] != VICTOIRE);
}

// III. Inscription dans la console et récupération des saisies. 

void SaisiesUtilisateur()
{
    int choice = 0;

    do
    {
        std::cout << "-- Acces aux parties de l'exercice 3 --" << std::endl;
        std::cout << "1 - Affichage et saisie de chaines de caracteres" << std::endl;
        std::cout << "2 - Affichage et saisie de nombre" << std::endl;
        std::cout << "3 - Bonus" << std::endl;

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
            SaisiePrenomNom();
            break;
        case 2:
            ComparaisonNombre();
            break;
        case 3:
            ComputerThink();
            break;
        default:
            std::cout << "Veuillez choisir entre 1, 2 ou 3 !" << std::endl;
        }
    } while (choice > 3);
}

int main(int argc, char *argv[])
{
    int choice = 0;

    do 
    {
        std::cout << "-- Acces aux parties de l'exercice --" << std::endl;
        std::cout << "1 - Manipulation des nombres" << std::endl;
        std::cout << "2 - Jeu de Tennis" << std::endl;
        std::cout << "3 - Inscription dans la console et recuperation des saisies" << std::endl;

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
            ManipulationNombres();
            break;
        case 2:
            Tennis();
            break;
        case 3:
            SaisiesUtilisateur();
            break;
        default:
            std::cout << "Veuillez choisir entre 1, 2 ou 3 !" << std::endl;
        }
    } while (choice > 3);

    system("pause");
}