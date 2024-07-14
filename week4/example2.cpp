#include <iostream>

using namespace std;

const double CONST_PI = 3.14159;

// ABSTRACT CLASS - All functions must be overidden (All functions are pure virtual functions)
class Shape {
protected:
    int sides;

public:
    Shape() {}

    // PVF: Pure Virtual Function
    // Function that does not do anything
    // It exists to be overridden.
    virtual double area() = 0; // {return 0;}
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) {
            sides = 1;
            radius = r;
        }

        double area() override {
            return CONST_PI * radius * radius;
        }
};

class Rectangle : public Shape {
    private:
        double length, width;

    public:
        Rectangle(double l, double w) {
            length = l;
            width = w;
        }

    double area() override {
        return length * width;
    }
};

int main() {
    // Shape s1; - Error: Cannot create an instance of an abstract class
    Circle c1(10);
    Shape* s2 = new Rectangle(10, 4); // new Circle(100)

    cout << c1.area() << endl;

    cout << s2->area() << endl;

    delete s2; // Don't forget to delete dynamically allocated memory

    return 0;
}
