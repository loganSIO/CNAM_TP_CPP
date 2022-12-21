#ifndef _MORPION_H
#define _MORPION_H
#include <iostream>
#include <vector>
#include "Grille.h"
#include "Jeu.h"
#include <cstdlib>
#include <string>

using namespace std;

class Morpion : public Jeu {

public:
    // Constructeur
    Morpion(int ColonneVector, int LigneVector) : Jeu(ColonneVector, LigneVector) {}

    //Signature des fonctions
    void jeuDuMorpion();
};

#endif
