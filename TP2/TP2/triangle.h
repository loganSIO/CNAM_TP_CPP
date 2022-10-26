#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle {
public:

	// Constructeur
	Triangle(const Point& pointA, const Point& pointB, const Point& pointC);

	// Destructeur
	~Triangle() = default;

	// Getters
	inline Point get_point_a() const {
		return _pointA;
	}
	inline Point get_point_b() const {
		return _pointB;
	}
	inline Point get_point_c() const {
		return _pointC;
	}

	// Setters
	inline void set_point_a(const Point& pointA) {
		_pointA = pointA;
	}
	inline void set_point_b(const Point& pointB) {
		_pointB = pointB;
	}
	inline void set_point_c(const Point& pointC) {
		_pointC = pointC;
	}

	// Méthodes
	void afficher() const;
	float base() const;
	float hauteur() const;
	float surface() const;
	float longueurs(const Point& p1, const Point& p2) const;
	bool est_isocele() const;
	bool est_rectangle() const;
	bool est_equilateral() const;

private:
	// Attributs
	Point _pointA, _pointB, _pointC;
};

#endif