#include <iostream>

using namespace std;

struct State {
    string name;
    int pop;
};

int main() {
    State one;
    State states[50];

    for (int i = 0; i < 50; i++) {
        states[i].pop = 0;
        states[i].name = "";
    }

    for (int i = 0; i < 50; i++) {
        cout << states[i].name << endl;
    }

    return 0;
}