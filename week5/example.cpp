#include <iostream>

using namespace std;

double divide(double num, double denom) {
    // Throwing int exception
    return denom == 0 ? throw -1 : num / denom;
}

int main() {
    double num, denom;

    cout << "Enter the numerator: ";
    cin >> num;
    cout << "\nEnter the denominator: ";
    cin >> denom;

    try {
        cout << divide(num, denom) << endl;
    } catch (char * ex) {
        cerr << "Const char exception caught" << endl;
    } catch (int Exception) {
        // Swallowed Exception - Exception that 
        //                       Does not handle anything
        cout << "Exception value: " << Exception << endl;
    } catch (...) {
        cerr << "Something else happened :(" << endl;
    }

    return 0;
}