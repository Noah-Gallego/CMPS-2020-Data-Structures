#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void fillArrRandom(int array[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        int num = (rand() % (max - min)) + min;
        array[i] = num;
    }
}

void fillArrIncrement(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i; 
    }
}

void fillArrDecrement(int array[], int size) {
    for (int i = size; i > 0; i--) {
        array[i] = i;
    }
}

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int array[], int size) {
    for (int i = 1; i < size - 1; i++) {
        int j = i;
        while (j > 0 && array[j - 1] > array[j]) {
            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j -= 1;
        }
    }
}

void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

void showArray(int array[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            cout << array[i] << ", ";
        } else {
            cout << array[i];
        }
    }
    cout << "]" << endl;
}

int main() {
    srand(time(NULL));
    // more code here
    int arraysize;
    cout << "Enter the size of the array: ";
    cin >> arraysize;
    int array[arraysize] = {0};

    cout << "The sort (Random) took ";
    fillArrRandom(array, arraysize, 1000, 1000000);

    auto start = chrono::steady_clock::now();
    selectionSort(array, arraysize);
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " milliseconds" << endl;
    if (arraysize < 100) {
        cout << "The SORTED Array: ";
        showArray(array, arraysize);
        cout << endl;
    }

    cout << "The sort (Increasing) took ";
    fillArrIncrement(array, arraysize);

    start = chrono::steady_clock::now();
    selectionSort(array, arraysize);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " milliseconds" << endl;
    if (arraysize < 100) {
        cout << "The SORTED Array: ";
        showArray(array, arraysize);
        cout << endl;
    }

    cout << "The sort (Decreasing) took ";
    fillArrDecrement(array, arraysize);

    start = chrono::steady_clock::now();
    selectionSort(array, arraysize);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " milliseconds" << endl;
    if (arraysize < 100) {
        cout << "The SORTED Array: ";
        showArray(array, arraysize);
        cout << endl;
    }

    return 0;
}
