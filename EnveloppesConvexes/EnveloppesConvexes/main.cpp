#include "Sommet.h"
#include "Point.h"
#include "Polygon.h"
#include "graphics.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;


void drawSommet(RenderWindow *window, Sommet *sommet)
{
	auto color = Color(200, 120, 10);
	auto suivant = sommet->next;

	Vertex line[] = {
		Vertex(Vector2f(sommet->point.x, sommet->point.y), color),
		Vertex(Vector2f(suivant->point.x, suivant->point.y))
	};

	window->draw(line, 2, Lines);
}

void drawPolygon(RenderWindow *window, Polygon *polygon)
{

	if (polygon->firstSummit == nullptr)
		return;

	drawSommet(window, polygon->firstSummit);
	auto suivant = polygon->firstSummit->next;
	while (suivant != polygon->firstSummit) {
		drawSommet(window, suivant);
		suivant = suivant->next;
	}
}

//void traceCircle(const Point& p)
//{
//	Point point = p;
//	circle (point.x, point.y, 10);
//}
//
//void traceCircles(vector<Point> points)
//{
//	int size = points.size();
//	for (int i = 0; i < size; i++)
//	{
//		traceCircle(points[i]);
//	}
//}
//
//bool sortByX(Point L, Point R)
//{
//	return L.x < R.x;
//}
//
//vector<Sommet*> getAGauc(const Polygon& pl, const Point& p) {
//	vector<Sommet*> rp;
//	Polygon plg = pl;
//	Point pt = p;
//	Sommet* ptr1 = plg.firstSummit;
//	Sommet* ptr = plg.firstSummit->next();
//	if (pt.aG(ptr1->point, ptr1->next()->getPoint()) == 1) {
//		rp.push_back(ptr1);
//	}
//	while (ptr != ptr1) {
//		if (pt.aG(ptr->point(), ptr->next()->getPoint()) == 1) {
//			rp.push_back(ptr);
//		}
//		ptr = ptr->next();
//	}
//	return rp;
//}
//
//void enveloppe(const vector<Point>& t, Polygon& p) {
//	int i = 0;
//	Polygon pl;
//	Point p1;
//	Point p2;
//	vector<Point> points = t;
//	vector<Sommet*> summit;
//	Sommet* si = pl.firstSummit;
//
//	sort(points.begin(), points.end(), sortByX);
//
//	pl.addSommet(points[i + 2]);
//
//	if (points[i].y() < points[i + 1].y()) {
//		p1 = points[i];
//		p2 = points[i + 1];
//	}
//	else {
//		p1 = points[i + 1];
//		p2 = points[i];
//	}
//
//	pl.addSommet(p1, pl.firstSummit());
//	pl.addSommet(p2, pl.firstSummit());
//	int pSz = points.size();
//	int sSz = 0;
//	for (int i = 3; i < pSz; i++) {
//
//		summit = getAGauche(pl, points[i]);
//
//		if (summit.size() == 1) {
//			pl.addSommet(points[i], summit[0]);
//		}
//		else if (summit.size() > 1) {
//			si = summit[0];
//			sSz = summit.size();
//			for (int z = 0; z < sSz; z++) {
//				if (si == summit[z]) {
//					si = si->getPrevSommet();
//					z = 0;
//				}
//			}
//
//			si = si->getNextSommet();
//			for (int y = 0; y < (sSz - 1); y++) {
//				pl.removeSummit(si->getNextSommet());
//			}
//			pl.addSommet(points[i], si);
//		}
//
//	}
//	refreshDisplay(pl, points);
//}

int main() 
{

	Point p1(rand() % 500, rand() % 300);
	Point p2(rand() % 500, rand() % 300);
	Point p3(rand() % 500, rand() % 300);
	Point p4(rand() % 500, rand() % 300);
	Point p5(rand() % 500, rand() % 300);
	Point p6(rand() % 500, rand() % 300);
	Point p7(rand() % 500, rand() % 300);
	Point p8(rand() % 500, rand() % 300);
	Point p9(rand() % 500, rand() % 300);

	vector<Point> points{ p1, p2, p3, p4, p5, p6, p7, p8, p9 };
	/*traceCircles(points);*/
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(600, 400), "EnvelopeConvexe", Style::Default, settings);

	Polygon myPolygon;
	auto firstSummit = myPolygon.addSommet(Point(10, 10), nullptr);
	auto secondSummit = myPolygon.addSommet(Point(240, 60), firstSummit);
	auto thirdSummit = myPolygon.addSommet(Point(340, 120), secondSummit);

	window.setActive();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Enter))
				window.close();
		}

		window.clear(Color(30, 45, 120));

		drawPolygon(&window, &myPolygon);

		window.display();
	}

	myPolygon.deleteSommet(firstSummit);
	myPolygon.deleteSommet(secondSummit);
	myPolygon.deleteSommet(thirdSummit);

	return 0;
}
