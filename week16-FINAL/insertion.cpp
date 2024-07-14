#include <iostream>
using namespace std;

void insertion(int arr[], int size) {
    int j, i, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

void showArray(int arr[], int size) {
    cout << "arr[" << size << "] = [";
    for (int i = 0; i < size; i++) { 
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int size = 10;
    int array[size] = {8, 6, 3, 6, 3, 7, 2, 6, 9, 10};
    insertion(array, size);

    showArray(array, size);

    return 0;
}