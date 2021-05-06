#ifndef POLYGON_H
#define POLYGON_H
#include "Sommet.h"

class Polygon
{
public:
	Polygon();
	Sommet *firstSummit;
	Sommet* addSommet(const Point& P, Sommet *s);
	void deleteSommet(Sommet* s);
};
#endif // !POLYGON_H
