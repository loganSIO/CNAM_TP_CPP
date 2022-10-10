#include <iostream>
#include <string>

#include "tennis.h"

void PrintScore(int pl, int score)
{
	std::string message = "";

	switch (score)
	{
		case AVANTAGE:
			message = "Avantage";
			break;
		case VICTOIRE:
			message = "Victoire";
			break;
		default:
			message = std::to_string(score);
			break;
	}
	std::cout << "Score Joueur " << pl << " : " << message << std::endl;
}

void CalculScore(int gagnant, int score[])
{
	int perdant = !gagnant;

	switch (score[gagnant])
	{
		case 0:
		case 15:
			score[gagnant] += 15;
			break;
		case 30:
			score[gagnant] += 10;
			break;
		case AVANTAGE:
			score[gagnant] = VICTOIRE;
			break;
		case 40:
			if (score[perdant] == AVANTAGE)
				score[perdant] == 40;

			else if (score[perdant] == 40)
				score[gagnant] = AVANTAGE;

			else
				score[gagnant] = VICTOIRE;
			break;
	}
}
