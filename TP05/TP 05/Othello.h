#include <iostream>
#include <vector>
#include "Grille.h"
#include <cstdlib>
#include <string>
using namespace std;

class Othello : public Grille {
public:
    // Constructeur
    Othello();
    //Signature des fonctions
    void jeuOthello();
    bool conversionPion();
};
