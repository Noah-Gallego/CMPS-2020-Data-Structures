#include <iostream>
using namespace std;

void selection(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    selection(array, size);

    showArray(array, size);

    return 0;
}