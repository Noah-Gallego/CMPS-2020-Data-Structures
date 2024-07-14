#include <iostream>

using namespace std;

int main() {
    double hours[7];
    string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    bool working[7] = {false, true, false, true, false, true, false}

    for (int i = 0; i < 7; i++) {
        double input;
        if (working[i]) {
            cout << "Enter input for " << days[i] << ": ";
            cin >> input;

            hours[i] = input;   
        }
    }

    return 0;
}