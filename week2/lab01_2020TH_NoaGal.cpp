#include <iostream>
using namespace std;

// Step 1
class Point {
  private: 
    double x, y;
  public:
    friend double operator*(Point p1, Point p2) {
        double w = abs(p1.x - p2.x);
        double h = abs(p1.y - p2.y);
        return w * h;
    }
    // Step 2
    Point(double _x, double _y) : x(_x), y(_y) {}

    // Step 3 & 4
    Point operator<(int n) {
        x -= n;
        Point temp(x, y);
        return temp;
    }

    Point operator>(int n) {
        x += n;
        Point temp(x, y);
        return temp;
    }

    // Step 7
    friend ostream &operator<<(ostream &lhs, Point rhs) {
        lhs << "(" << rhs.x << ", " << rhs.y << ")";
        return lhs;
    }

};

int main() {
    Point p1(5, 5), p2(10, 10);

    p1 = p1 < 1;
    p2 = p2 > 3;

    cout << p1 << endl;
    cout << p2 << endl;

    double area = p1 * p2;
    cout << "Area bounded by p1 and p2 is " << area << endl;

    return 0;
}