#ifndef SOMMET_H
#define SOMMET_H
#include "Point.h"

class Sommet
{
public:
	Sommet(Point point);
	Point point;
	Sommet *prev, *next;
};
#endif // !SOMMET_H
