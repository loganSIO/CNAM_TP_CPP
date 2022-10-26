#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "triangle.h"

Triangle::Triangle(const Point& pointA, const Point& pointB, const Point& pointC)
	: _pointA(pointA), _pointB(pointB), _pointC(pointC)
{}

void Triangle::afficher() const {
	std::cout << "-- Triangle --" << std::endl
		<< "Base : " << base() << std::endl
		<< "Hauteur : " << hauteur() << std::endl
		<< "Surface : " << surface() << std::endl
		<< "Isocele : " << est_isocele() << std::endl
		<< "Rectangle : " << est_rectangle() << std::endl
		<< "Equilateral : " << est_equilateral() << std::endl;
}

// Retourne la plus longue distance entre deux points (= la base)
float Triangle::base() const {
	const float distanceAB = longueurs(_pointA, _pointB);
	const float distanceAC = longueurs(_pointA, _pointC);
	const float distanceBC = longueurs(_pointB, _pointC);

	if (distanceAB > distanceAC && distanceAB > distanceBC) {
		return distanceAB;
	}
	else if (distanceAC > distanceAB && distanceAC > distanceBC) {
		return distanceAC;
	}
	return distanceBC;
}

// Calcul de la hauteur avec la formule de Héron
float Triangle::hauteur() const {
	return (2 * surface() / base());
}

// Calcul de la surface avec la formule de Héron
float Triangle::surface() const {
	const float distanceAB = longueurs(_pointA, _pointB);
	const float distanceAC = longueurs(_pointA, _pointC);
	const float distanceBC = longueurs(_pointB, _pointC);
	const float d = (distanceAB + distanceAC + distanceBC) / 2;

	const float a = sqrt(d * (d - distanceAB) * (d - distanceAC) * (d - distanceBC));

	return a;
}

// Calcul la longueur la longueur entre deux points
float Triangle::longueurs(const Point& p1, const Point& p2) const {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Verifie si un triangle est isocele
// un triangle est isocele si deux de ses longueurs sont égales
// retourne true (1) s'il est isocele, false (0) s'il ne l'est pas
bool Triangle::est_isocele() const {
	const float distanceAB = longueurs(_pointA, _pointB);
	const float distanceAC = longueurs(_pointA, _pointC);
	const float distanceBC = longueurs(_pointB, _pointC);

	if (distanceAB == distanceAC || distanceAB == distanceBC
		|| distanceAC == distanceBC) {
		return true;
	}
	return false;
}

// Verifie si un triangle est rectangle
// un triangle est rectangle si une de ses longueurs
// au carré est égale à la multiplicaitons deux autres longueurs au carré 
// retourne true (1) s'il est rectangle, false (0) s'il ne l'est pas
bool Triangle::est_rectangle() const {
	const float distanceAB = longueurs(_pointA, _pointB);
	const float distanceAC = longueurs(_pointA, _pointC);
	const float distanceBC = longueurs(_pointB, _pointC);

	if (pow(distanceAB, 2) == pow(distanceAC, 2) + pow(distanceBC, 2) 
		|| pow(distanceAC, 2) == pow(distanceAB, 2) + pow(distanceBC, 2)
		|| pow(distanceBC, 2) == pow(distanceAB, 2) + pow(distanceAC, 2)) {
		return true;
	}
	return false;
}

// Verifie si un triangle est equilateral
// un triangle est equilateral si toutes ses longueurs sont égales
// retourne true (1) s'il est equilateral, false (0) s'il ne l'est pas
bool Triangle::est_equilateral() const {
	const float distanceAB = longueurs(_pointA, _pointB);
	const float distanceAC = longueurs(_pointA, _pointC);
	const float distanceBC = longueurs(_pointB, _pointC);

	if (distanceAB == distanceAC && distanceAC == distanceBC) {
		return true;
	}
	return false;
}