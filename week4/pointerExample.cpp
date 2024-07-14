#include <iostream>

using namespace std;

int * makeInt(int value) {
    // int data = value;
    // return &data; WILL NOT WORK :(

    int *newInt = new int;
    *newInt = value;
    return newInt;
}

int main() {
    int *m = makeInt(5);
    cout << m << endl;

    delete m;
    return 0;
}