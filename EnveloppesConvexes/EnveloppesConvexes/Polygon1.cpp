#include <iostream>
#include <string>
#ifndef POINTCPP
#define POINTCPP
#include "Point1.cpp"
#endif
#ifndef SUMMITCPP
#define SUMMITCPP
#include "Sommet1.cpp"
#endif

class Polygone {
private:
    Sommet* summit;
public:
    Polygone(Sommet* s = nullptr) :summit(s) {};

    void toString() {
        cout << "Polygone: ";
    }
    Sommet* getSommet() {
        return summit;
    }
    void setSommet(Sommet* s) {
        summit = s;
    }
    Sommet* addSommet(const Point& p, Sommet* s = nullptr) {
        Sommet* newSummit = nullptr;
        newSummit = new Sommet(p);
        if (s != NULL) {
            newSummit->setPrevSommet(s);
            newSummit->setNextSommet(s->getNextSommet());
            s->getNextSommet()->setPrevSommet(newSummit);
            s->setNextSommet(newSummit);
            summit = newSummit;

        }
        else {
            newSummit->setPrevSommet(newSummit);
            newSummit->setNextSommet(newSummit);
            summit = newSummit;
        }
        return summit;
    }
    void removeSummit(Sommet* s) {
        Sommet* prevSummit = s->getPrevSommet();
        Sommet* nextSummit = s->getNextSommet();
        prevSummit->setNextSommet(nextSummit);
        nextSummit->setPrevSommet(prevSummit);
        s->setNextSommet(nullptr);
        s->setPrevSommet(nullptr);
    }
};