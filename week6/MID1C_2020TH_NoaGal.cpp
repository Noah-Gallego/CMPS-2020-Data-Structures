#include <iostream>

using namespace std;

class Car {
    private:
        string name;
        double weight;
    public:
        Car(string n, double w) {
            name = n;
            weight = w;
        }

        string getName() {
            return name;
        }

        bool operator > (Car &c) {
            return weight > c.weight;
        }
};



int main() {
    Car c1("Tesla", 2500);
    Car c2("BYD", 3000);

    if (c1 > c2) {
        cout << c1.getName() << " is heavier" << endl;
    } else {
        cout << c2.getName() << " is heavier" << endl;
    }

    return 0;
}