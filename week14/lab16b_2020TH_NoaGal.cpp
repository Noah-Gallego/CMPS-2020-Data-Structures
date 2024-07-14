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

// I did not get the point of the pivot pos, so I did not make the funciton 
// I just started at the end of the array :)

int partition(int array[], int start, int end) {
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (array[j] < pivot) {
             i++;
             // Swap Values
             int temp = array[i];
             array[i] = array[j];
             array[j] = temp;
        }
    }
    i++;
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;

    return i;
}

void quickSort(int array[], int start, int end) {
    if (end <= start) return; 

    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}


int main() {
    srand(time(NULL));
    // more code here
    int arraysize;
    cout << "Enter the size of the array: ";
    cin >> arraysize;
    int array[arraysize] = {0};

    cout << "The sort (Random) took ";
    fillArrRandom(array, arraysize, 1, 20);

    auto start = chrono::steady_clock::now();
    quickSort(array, 0, arraysize - 1);
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " milliseconds" << endl;
    if (arraysize < 100) {
        cout << "The SORTED Array: ";
        showArray(array, arraysize);
        cout << endl;
    }


    int newArr[9] = {31, 4, 15, 9, 26, 5, 35, 8, 97};
    partition(newArr, 0, 9);
    partition([0, 4, 15, 9, 26, 5, 8, 31, 97], 0, 9);
    showArray(newArr, 9);

    return 0;
}
