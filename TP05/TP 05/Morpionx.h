#ifndef VERSION_3_TEST_TP3_MORPIONX_H
#define VERSION_3_TEST_TP3_MORPIONX_H
#include <iostream>
#include <vector>
#include "Grille.h"
#include "Jeu.h"
#include <cstdlib>
#include <string>


using namespace std;

class Morpionx : public Jeu {

public:
    // Constructeur
    Morpionx(int ColonneVector, int LigneVector) : Jeu(ColonneVector, LigneVector) {}

    //Signature des fonctions
    void jeuDuMorpionx();
};

#endif //VERSION_3_TEST_TP3_MORPIONX_H
