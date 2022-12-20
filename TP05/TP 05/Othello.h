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
    bool remplacerLigneOthello(int x, int y, int joueur_actuel);
    bool remplacerColonneOthello(int x, int y, int joueur_actuel);
    bool remplacerDiagonaleOthello(int x, int y, int joueur_actuel);
    void demandeSaisieOthello(int joueur_actuel);
};
