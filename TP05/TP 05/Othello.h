#ifndef _OTHELLO_H
#define _OTHELLO_H
#include <iostream>
#include <vector>
#include "Grille.h"
#include "Jeu.h"
#include <cstdlib>
#include <string>
using namespace std;

class Othello : public Jeu  {
public:
    // Constructeur
    Othello(int ColonneVector, int LigneVector) : Jeu(ColonneVector, LigneVector) {}

    //Signature des fonctions
    void jeuOthello();
};

#endif