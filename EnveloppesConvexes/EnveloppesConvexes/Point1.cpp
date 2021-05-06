#include <iostream>
#include <string>

using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int abs = 0, int ord = 0) :x(abs), y(ord) {};

    void toString() {
        string px = to_string(x);
        string py = to_string(y);
        cout << "Point : x: " << px << " y: " << py << "\n";
    }
    int getX() {
        return x;
    }
    void setX(int x) {
        this->x = x;
    }
    int getY() {
        return y;
    }
    void setY(int y) {
        this->y = y;
    }

    int aGauche(const Point& a, const Point& b) {
        int d = ((b.x - a.x) * (y - a.y)) - ((x - a.x) * (b.y - a.y));
        int i = 0;
        if (d < 0) {
            i = -1;
        }
        else if (d > 0) {
            i = 1;
        }
        return i;
    }
};