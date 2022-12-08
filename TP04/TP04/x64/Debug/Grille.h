#ifndef VERSION_3_TEST_TP3_GRILLE_H
#define VERSION_3_TEST_TP3_GRILLE_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class Grille {

public:

    //Constructeur
    Grille(const int ColonneVector, const int LigneVector);

    // Getters/Setters
    void setLignevector(const int lv);
    int getLignevector() const;
    void setColonnevector(const int cv);
    int getColonnevector() const;


    // Signature des fonctions
    void initialiserGrille();
    void afficheGrille();
    bool porteeGrille(const int saisiecolonne, const int saisieligne) const;
    bool caseVide(const int saisiecolonne, const int saisieligne) const;
    void insererPoint(int saisiecolonne, int saisieligne, int id);
    bool videGrille();
    void demandeSaisie(int joueur_actuel);
    bool demandeSaisieColonne(int joueur_actuel);
    string j1OuJ2();
    std::vector<std::vector<int> > grille = std::vector<std::vector<int> > (lignevector);

    int lignevector;
    int colonnevector;
};




#endif //VERSION_3_TEST_TP3_GRILLE_H
