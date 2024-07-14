#include <iostream>

using namespace std;

class Height {
    private:
        double feet, inches;
    public:
        void setFeet(double f) {
            feet = f;
        }

        void setInches(double i) {
            inches = i;
        }

        double getInches() {
            return inches;
        }

        double getFeet() {
            return feet;
        }
};

int main() {
    Height h1;
    double ft, in;
    
    cout << "Enter the height in feet: ";
    cin >> ft;

    cout << "\nEnter the inches: ";
    cin >> in;
    h1.setFeet(ft);
    h1.setInches(in);

    cout << h1.getFeet() << " feet and " << h1.getInches() << " inches." << endl;
}