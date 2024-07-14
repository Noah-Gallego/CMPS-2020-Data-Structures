#include <iostream>
using namespace std;

class Averager {
    private:
        int count = 0;
        double total = 0;
    public:
        Averager &add(int value) {
            count++;
            total += value;
            return *this;
        }

        double calc() {
            return total / count;
        }

};  

int main() {
    Averager avg;
    double averageCalculated = avg.add(10).add(20).add(30).calc();

    cout << "Average: " << averageCalculated << endl;
    return 0;
}