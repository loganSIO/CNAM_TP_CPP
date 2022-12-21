#ifndef VERSION_3_TEST_TP3_JEU_H
#define VERSION_3_TEST_TP3_JEU_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Grille.h"

using namespace std;

class Jeu : public Grille {

public:

    //Constructeur
    Jeu(int ColonneVector, int LigneVector) : Grille(ColonneVector, LigneVector) {}

    // Signature des fonctions
    // Morpion
    void demandeSaisieMorpion(int joueur_actuel);
    bool gagnerLigne();
    bool gagnerDiagonale();
    bool gagnerColonne();
    // Puisssance 4
    bool demandeSaisiePuissance4(int joueur_actuel);
    bool gagnerLignePuissance();
    bool gagnerDiagonalePuissance();
    bool gagnerColonnePuissance();

    // Othello
    void demandeSaisieMorpionOthello(int joueur_actuel);
    bool remplacerLigneOthello(int x, int y, int joueur_actuel);
    bool remplacerColonneOthello(int x, int y, int joueur_actuel);
    bool remplacerDiagonaleOthello(int x, int y, int joueur_actuel);

    bool gagneZero();

};

#endif
