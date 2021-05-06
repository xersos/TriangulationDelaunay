#include <iostream>
#include <string>
#ifndef SUMMITCPP
#define SUMMITCPP
#include "Sommet1.cpp"
#endif

using namespace std;

class DemiCote {
private:
    int marque;
    Sommet* sommet;
    DemiCote* prevDemiCote;
    DemiCote* nextDemiCote;
    DemiCote* oppositeDemiCote;

public:
    DemiCote(Sommet* s = nullptr, DemiCote* prv = nullptr, DemiCote* n = nullptr, DemiCote* o = nullptr) {
        sommet = s;
        prevDemiCote = prv;
        nextDemiCote = n;
        oppositeDemiCote = o;
        marque = 0;
    };
    int getMarque() {
        return marque;
    }
    void setMarque(int m) {
        marque = m;
    }
    Sommet* getSommet() {
        return sommet;
    }
    void setSommet(Sommet* s) {
        sommet = s;
    }
    DemiCote* getPrevDemiCote() {
        return prevDemiCote;
    }
    void setPrevDemiCote(DemiCote* p) {
        prevDemiCote = p;
    }
    DemiCote* getNextDemiCote() {
        return nextDemiCote;
    }
    void setNextDemiCote(DemiCote* n) {
        nextDemiCote = n;
    }
    DemiCote* getOppositeDemiCote() {
        return oppositeDemiCote;
    }
    void setOppositeDemiCote(DemiCote* o) {
        this->oppositeDemiCote = o;
    }
    void toString() {
        cout << "Demi Cote" << endl;
        if (sommet != nullptr) {
            sommet->toString();
        }
        else {
            cout << "No Summit" << endl;
        }
        cout << "\n";
    }
};