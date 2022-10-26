#include <iostream>

#include "rectangle.h"

Rectangle::Rectangle(const int longueur, const int largeur)
	: _longueur(longueur), _largeur(largeur)
{
}

Rectangle r2(100, 200);

void Rectangle::afficher() const {
	std::cout << "-- Rectangle --" << std::endl
		<< "Longeur : " << _longueur << std::endl
		<< "Largeur : " << _largeur << std::endl
		<< "Surface : " << surface() << std::endl
		<< "Perimetre : " << perimetre() << std::endl
		<< "Comparaison perimetre : " << plus_grand_perimetre(r2) << std::endl
		<< "Comparaison surface : " << plus_grande_surface(r2) << std::endl;
}

int Rectangle::perimetre() const {
	return (_longueur + _largeur) * 2;
}

int Rectangle::surface() const {
	return _longueur * _largeur;
}

bool Rectangle::plus_grand_perimetre(Rectangle r2) const {
	return r2.perimetre() > perimetre();
}

bool Rectangle::plus_grande_surface(Rectangle r2) const {
	return r2.surface() > surface();
}