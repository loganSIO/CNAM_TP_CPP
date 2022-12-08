#ifndef VERSION_4_TP_3_MORPION_DELTA_VERSION_PUISSANCE4_H
#define VERSION_4_TP_3_MORPION_DELTA_VERSION_PUISSANCE4_H
#include <iostream>
#include <vector>
#include "Grille.h"
#include <cstdlib>
#include <string>
using namespace std;

class Puissance4 : public Grille {
public:
    // Constructeur
    Puissance4();
    //Signature des fonctions
    void jeuPuissance4();
    bool gagnerLignePuissance();
    bool gagnerDiagonalePuissance();
    bool gagnerColonnePuissance();
};


#endif //VERSION_4_TP_3_MORPION_DELTA_VERSION_PUISSANCE4_H
