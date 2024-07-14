#include <iostream>

using namespace std;

// FIND FN
template <typename T>
bool find(T arr[], T value) {
    for (int i = 0; i < 5; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

// COUNT FN 
template <typename T>
int count(T arr[], T value) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

// EC - LOCATE FN 
template <typename T>
int locate(T arr[], T value) {
    int index = -1;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return index;
}

int main() {
    int fib[5] = {1, 1, 2, 3, 5};
    string matter[5] = {"fire", "water", "earth", "water", "air"};

    //shows found
    cout << (find<int>(fib, 3) ? "" : "Not ") << "Found" << endl;

    // shows not found
    cout << (find<string>(matter, "iron") ? "" : "Not ") << "Found" << endl; 

    cout << count<int>(fib, 1) << endl;             // shows 2
    cout << count<string>(matter, "earth") << endl; // shows 1

    // EXTRA CREDIT
    cout << locate<int>(fib, 1) << endl;            // shows 0
    cout << locate<string>(matter, "gold") << endl; // shows -1

    return 0;   
}