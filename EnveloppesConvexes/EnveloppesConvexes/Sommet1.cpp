#include <iostream>
#include <string>
#ifndef POINTCPP
#define POINTCPP
#include "Point1.cpp"
#endif
using namespace std;

class Sommet {
private:
    Point point;
    Sommet* prev, * next;
public:
    Sommet(const Point& point, Sommet* prevSummit = nullptr, Sommet* nextSummit = nullptr) :point(point), prev(prevSummit), next(nextSummit) {};

    void toString() {
        cout << "Summit: \n";
        point.toString();
        if (prev != nullptr) {
            string px = to_string(this->prev->getPoint().getX());
            string py = to_string(this->prev->getPoint().getY());
            cout << "Previous point coordinates: x: " << px << " y: " << py << "\n";
        }
        else {
            cout << "No previous summit\n";
        }
        if (next != nullptr) {
            string px = to_string(this->next->getPoint().getX());
            string py = to_string(this->next->getPoint().getY());
            cout << "Next point coordinates: x: " << px << " y: " << py << "\n";
        }
        else {
            cout << "No next summit\n";
        }
        cout << "\n";
    }
    Point getPoint() {
        return point;
    }
    void setPoint(Point p) {
        point = p;
    }
    Sommet* getPrevSommet() {
        if (prev == NULL) {
            cout << "Not Prev Summit" << endl;
        }
        return prev;
    }
    void setPrevSommet(Sommet* s) {
        prev = s;
    }
    Sommet* getNextSommet() {
        if (next == NULL) {
            cout << "Not Next Summit" << endl;
        }
        return next;
    }
    void setNextSommet(Sommet* s) {
        next = s;
    }
    void zeVoid() {

    }
};