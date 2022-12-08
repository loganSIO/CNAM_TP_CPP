#ifndef VERSION_3_TEST_TP3_MORPIONX_H
#define VERSION_3_TEST_TP3_MORPIONX_H
#include <iostream>
#include <vector>
#include "Grille.h"
#include <cstdlib>
#include <string>


using namespace std;

class Morpionx : public Grille {

public:
    // Constructeur
    Morpionx();

    //Signature des fonctions
    void jeuDuMorpionx();
    bool gagnerLigne();
    bool gagnerDiagonale();
    bool gagnerColonne();
};



#endif //VERSION_3_TEST_TP3_MORPIONX_H
