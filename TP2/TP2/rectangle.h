#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle {
	public:
		// Construteur
		Rectangle(const int longueur, const int largeur);

		// Destructeur
		~Rectangle() = default;

		// Getters
		inline int get_longueur() const {
			return _longueur;
		}
		inline int get_largeur() const {
			return _largeur;
		}
		inline Point get_coin_superieur_gauche() const {
			return _coinSuperieurGauche;
		}

		// Setters
		inline void set_longueur(const int longueur) {
			_longueur = longueur;
		}
		inline void set_largeur(const int largeur) {
			_largeur = largeur;
		}
		inline void set_coin_superieur_gauche(const Point& coinSuperieurGauche) {
			_coinSuperieurGauche = coinSuperieurGauche;
		}

		// Méthodes
		void afficher() const;
		int perimetre() const;
		int surface() const;
		bool plus_grand_perimetre(Rectangle r2) const;
		bool plus_grande_surface(Rectangle r2) const;

	private:
		// Attributs
		int _longueur;
		int _largeur;
		Point _coinSuperieurGauche;
};

#endif