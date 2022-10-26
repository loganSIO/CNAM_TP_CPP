#include <iostream>

#include "point.h"
#include "rectangle.h"
#include "cercle.h"
#include "triangle.h"

int main()
{
	Rectangle r1(20, 30);
	Cercle c1(8, { -1, 0 });
	Triangle t1({1, 3}, {7, 2}, {1, 2});

	r1.afficher();
	c1.afficher();
	t1.afficher();

	system("pause");
}