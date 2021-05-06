#include "Polygon.h"

Polygon::Polygon()
{
	firstSummit = nullptr;
};

Sommet* Polygon::addSommet(const Point& P, Sommet* s)
{
	Sommet* newSummit = new Sommet(P);
	if (s == nullptr)
	{
		newSummit->next = newSummit;
		newSummit->prev = newSummit;
		firstSummit = newSummit;
	}
	else
	{
		newSummit->next = s->next;
		newSummit->prev = s;
		s->next = newSummit;
	}

	return newSummit;
}

void Polygon::deleteSommet(Sommet* s)
{
	s->prev->next = s->next;
	s->next->prev = s->prev;

	delete s;
}