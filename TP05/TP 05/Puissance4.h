#ifndef _PUISSANCE4_H
#define _PUISSANCE4_H
#include <iostream>
#include <vector>
#include "Grille.h"
#include "Jeu.h"
#include <cstdlib>
#include <string>
using namespace std;

class Puissance4 : public Jeu {
public:
    // Constructeur
    Puissance4(int ColonneVector, int LigneVector) : Jeu(ColonneVector, LigneVector) {}

    //Signature des fonctions
    void jeuPuissance4();
};


#endif 
