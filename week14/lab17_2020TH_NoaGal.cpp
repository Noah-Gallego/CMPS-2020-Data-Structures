#include <iostream>
#include <cstdlib>
using namespace std;
// TRAVERSING DOWNWARDS:
//                  n
//         (2n + 2)   (2n + 1)

// TRAVERSING UPWARDS:
//                  n
// 1.      P = int((c-1) / 2)
// 2.  (P * 2) + 1     (P * 2 + 1)         

void fillArrRandom(int array[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        int num = (rand() % (max - min)) + min;
        array[i] = num;
    }
}


bool isMaxHeap(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int parent = int((i - 1) / 2);
        if (array[parent] < array[i]) return false;
    }   

    return true;
}

void heapify(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int parent = int((i - 1) / 2);
        if (array[parent] > array[i]) {
            int temp = array[i];
            array[i] =  array[parent];
            array[parent] = temp;

            heapify(array, size);
        }
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
    int size = 10;
    int array[size] = {0};
    fillArrRandom(array, size, 1, 20);
    showArray(array, size);
    cout << "isMaxHeap(): " << isMaxHeap(array, size) << "\n" << endl;

    if (!isMaxHeap(array, size)) heapify(array, size);
    showArray(array, size);
    cout << "UPDATED isMaxHeap(): " << isMaxHeap(array, size) << endl;
    return 0;
}