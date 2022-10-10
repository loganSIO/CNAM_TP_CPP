#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "saisies.h"

// III 1.1 && 1.2
void SaisiePrenomNom()
{
	std::cout << "Entrez votre nom et prenom" << std::endl;

	std::string nom;
	std::string prenom;
	std::cin >> nom;
	std::cin >> prenom;
	prenom[0] = toupper(prenom[0]);
	std::transform(nom.begin(), nom.end(), nom.begin(), ::toupper);

	std::cout << "Coucou " << nom << " " << prenom << " !" << std::endl;
}

// III 2.1 & 2.2

void ComparaisonNombre()
{
	srand(time(NULL));
	int nb;
	int randomNumber = rand() % 1001;

	do
	{
		for (int i = 0; i < 1001; i++) {

			std::cout << "Veuillez saisir un nombre entier : " << std::endl;

			// Vérification si nb est un int 
			while (true)
			{
				std::cin >> nb;

				if (!std::cin)
				{
					std::cout << "Veuillez saisir un nombre entier." << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				else break;
			}

			if (nb > randomNumber)
				std::cout << "Votre nombre : " << nb << " est plus grand que le nombre aleatoire" << std::endl;

			else if (nb < randomNumber)
				std::cout << "Votre nombre : " << nb << " est plus petit que le nombre aleatoire" << std::endl;

			else
				std::cout << "Votre nombre : " << nb << " est egal au nombre aleatoire : " << randomNumber <<
				". \tFelicitations !\t Cela t'auras juste pris " << i << " essais" << std::endl;
		}
	} while (nb != randomNumber);
}

/// III 2.3

void ComputerThink()
{
	int essais = 0;
	int BorneMax = 1001;
	int BorneMin = 0;
	int nb;
	int randomNumber = 0;
	bool nbToFind = false;

	std::cout << "Veuillez saisir un nombre entre 0 et 1000" << std::endl;

	// Vérification si nb est un int et <= 1000
	while (true)
	{
		std::cin >> nb;

		if (!std::cin)
		{
			std::cout << "Veuillez saisir un nombre entier." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		else if (nb > 1000)
		{
			std::cout << "Entre 0 et 1000 on a dit !" << std::endl;
			std::cin.clear();
			continue;
		}

		else break;
	}

	while (!nbToFind)
	{
		randomNumber = (BorneMin + BorneMax) / 2;

		std::cout << "Nombre de l'ordinateur : " << randomNumber << std::endl;
		++essais;

		// On réduit les bornes à chaque fois que l'ordi se trompe
		if (nb > randomNumber)
		{
			std::cout << "Beep boop : " << randomNumber << " est plus petit que le nombre de l'utilisateur" << std::endl;
			BorneMin = randomNumber + 1;
		}

		else if (nb < randomNumber)
		{
			std::cout << "Beep boop : " << randomNumber << " est plus grand que le nombre de l'utilisateur" << std::endl;
			BorneMax = randomNumber - 1;
		}

		else if (randomNumber == nb)
		{
			std::cout << "Beep boop : " << randomNumber << " est egal au nombre de l'utilisateur : " << nb <<
				". \tFelicitations !\t Cela lui a prit " << essais << " essais" << std::endl;
			nbToFind = true;
		}
	}
}