#include <iostream>
#include <cmath>

using namespace std;

class Point {
    private:
    // Class Variables
        double x, y;
    public:
    // Setters and Getters
        void setCoords(double _x, double _y) {
            x = _x;
            y = _y;
        }
        double getXValue() {
            return x;
        }

        double getYValue() {
            return y;
        }
};

class Map {
    private:
        // Class Variables 
        Point tl, br;
    public:
        // Map member initialization (in constructor) & Calculated Area between two give points
        Map(Point _tl, Point _br) : tl(_tl), br(_br) {}

        /* SAME AS:
        Map(Point _tl, Point _br) {
            tl = _tl;
            br = _br;
        }
        */ 

        double calcArea() {
            double w = abs(br.getXValue() - tl.getXValue());
            double h = abs(br.getYValue() - tl.getYValue());
            return w * h;
        }
};

int main() {
    Point p1, p2;

    p1.setCoords(3, 3);
    p2.setCoords(6, 7);

    Map m(p1, p2);

    cout << "The area of the given points is " << m.calcArea() << "." << endl;

    return 0;
}