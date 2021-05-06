#include <iostream>
#include <string>
#include <vector>

#ifndef DEMICOTECPP
#define DEMICOTECPP
#include "DemiCote.cpp"
#endif

using namespace std;

class Carte {
private:
    vector<DemiCote*> demiCotes;
public:
    Carte() {};

    vector<DemiCote*> getDemiCotes() {
        return demiCotes;
    }
    void setDemiCotes(vector<DemiCote*> d) {
        demiCotes = d;
    }
    DemiCote* ajouteDemiCote(DemiCote* suiv, DemiCote* opp = nullptr) {
        DemiCote* newDemiCote;
        newDemiCote = new DemiCote(nullptr, nullptr, suiv, opp);
        demiCotes.push_back(newDemiCote);
        return newDemiCote;
    }
    DemiCote* ajouteDemiCote(const Point& p, DemiCote* opp = nullptr) {
        DemiCote* newDemiCote;
        Point point = p;
        Sommet s(point, nullptr, nullptr);
        newDemiCote = new DemiCote(&s, nullptr, nullptr, opp);
        demiCotes.push_back(newDemiCote);
        return newDemiCote;
    }
    DemiCote* ajouteCote(DemiCote* suiv1, DemiCote* suiv2) {
        DemiCote* d1 = suiv1;
        DemiCote* d2 = suiv2;
        d1->setOppositeDemiCote(d2);
        d2->setOppositeDemiCote(d1);
        d1->setNextDemiCote(suiv1);
        d2->setNextDemiCote(suiv2);
        demiCotes.push_back(d1);
        demiCotes.push_back(d2);
        return d1;
    }
    DemiCote* ajouteCote(DemiCote* suiv1, const Point& p2) {
        Point p = p2;
        Sommet s(p, nullptr, nullptr);
        DemiCote* d1;
        DemiCote* d2;
        d1 = new DemiCote(nullptr, nullptr, suiv1, nullptr);
        d2 = new DemiCote(&s, nullptr, nullptr, nullptr);
        d1->setOppositeDemiCote(d2);
        d2->setOppositeDemiCote(d1);
        d1->setNextDemiCote(suiv1);
        demiCotes.push_back(d1);
        demiCotes.push_back(d2);
        return d1;
    }
    DemiCote* ajouteCote(const Point& p1, DemiCote* suiv2) {
        Point p = p1;
        Sommet s(p, nullptr, nullptr);
        DemiCote* d1;
        DemiCote* d2;
        d1 = new DemiCote(&s, nullptr, nullptr, nullptr);
        d2 = new DemiCote(nullptr, nullptr, suiv2, nullptr);
        d1->setOppositeDemiCote(d2);
        d2->setOppositeDemiCote(d1);
        demiCotes.push_back(d1);
        demiCotes.push_back(d2);
        return d1;
    }
    DemiCote* ajouteCote(const Point& p1, const Point& p2) {
        Point pt1 = p1;
        Point pt2 = p2;
        Sommet s1(pt1, nullptr, nullptr);
        Sommet s2(pt2, nullptr, nullptr);
        DemiCote* d1;
        DemiCote* d2;
        d1 = new DemiCote(&s1, nullptr, nullptr, nullptr);
        d2 = new DemiCote(&s2, nullptr, nullptr, nullptr);
        d1->setOppositeDemiCote(d2);
        d2->setOppositeDemiCote(d1);
        demiCotes.push_back(d1);
        demiCotes.push_back(d2);
        return d1;
    }
    void toString() {
        cout << "Map:" << endl;
        if (this->demiCotes.size() > 0) {
            this->demiCotes[this->demiCotes.size() - 1]->toString();
        }
        else {
            cout << "No Semi-Sides" << endl;
        }
    }
};