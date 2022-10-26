#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "cercle.h"

Cercle::Cercle(const int diametre, const Point centreCercle)
	: _diametre(diametre), _centreCercle(centreCercle)
{}

void Cercle::afficher() const {
	std::cout << "-- Cercle --" << std::endl
		<< "Centre : " << _centreCercle.x << "," << _centreCercle.y << std::endl
		<< "Diametre : " << _diametre << std::endl
		<< "Perimetre : " << perimetre() << std::endl
		<< "Surface : " << surface() << std::endl
		<< "Point sur le cercle : " << est_sur_cercle({ 23, 15 }) << std::endl
		<< "Point est dans le cercle : " << est_dans_cercle({ 2, 2}) << std::endl;
}

float Cercle::perimetre() const {
	return (M_PI * _diametre);
}

float Cercle::surface() const {
	return (pow(_diametre / 2, 2) * M_PI);
}

// True (1) si un point est sur le cercle, false (0) s'il ne l'est pas
bool Cercle::est_sur_cercle(Point p) const {
	return sqrt(pow(p.x - _centreCercle.x, 2) + pow(p.y - _centreCercle.y, 2)) ==  _diametre / 2;
}

// True (1) si un point est dans le cercle, false (0) s'il ne l'est pas
bool Cercle::est_dans_cercle(Point p) const {
	return sqrt(pow(p.x - _centreCercle.x, 2) + pow(p.y - _centreCercle.y, 2)) < _diametre / 2;
}