#include <iostream>

using namespace std;

class Calendar {
    public:
        int day;
        int month;
        int year;

        Calendar(int d, int m, int y) {
            day = d;
            month = m;
            year = y;
        }
        
        bool isLeapDay() {
            if (year % 4 == 0 && day == 29 && month == 2) {
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    Calendar c(29, 2, 2024);
    cout << c.isLeapDay() << endl;
    return 0;
}