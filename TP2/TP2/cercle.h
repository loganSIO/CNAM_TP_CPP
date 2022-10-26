#ifndef CERCLE_H
#define CERCLE_H

#include "point.h"

class Cercle {
	public:

		// Constructeur
		Cercle(const int diametre, const Point centreCercle);

		// Destructeur
		~Cercle() = default;

		// Getters
		inline int get_diametre() const {
			return _diametre;
		}
		inline Point get_centre_cercle() const {
			return _centreCercle;
		}

		// Setters
		inline void set_diametre(const int diametre) {
			_diametre = diametre;
		}
		inline void set_centre_cercle(const Point& centreCercle) {
			_centreCercle = centreCercle;
		}

		// Méthodes
		void afficher() const;
		float perimetre() const;
		float surface() const;
		bool est_sur_cercle(const Point p) const;
		bool est_dans_cercle(const Point p) const;

	private:
		// Attributs
		int _diametre;
		Point _centreCercle;
};

#endif