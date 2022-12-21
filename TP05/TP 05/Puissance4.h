#ifndef VERSION_4_TP_3_MORPION_DELTA_VERSION_PUISSANCE4_H
#define VERSION_4_TP_3_MORPION_DELTA_VERSION_PUISSANCE4_H
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


#endif //VERSION_4_TP_3_MORPION_DELTA_VERSION_PUISSANCE4_H
