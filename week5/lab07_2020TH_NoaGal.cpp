#include <iostream>

using namespace std;

template <typename Type>
double average(Type arr[], int size) {
    auto sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

template <typename ShowType>
void show(ShowType arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            cout << arr[i] << ", ";
        } else {
            cout << arr[i] << "]" << endl;
        }
    }
}

template <> void show(string arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

template <typename T>
T* getInput(T arr[], int size) {
    int i = 0;

    while (i < size) {
        cout << "Enter entry " << i + 1 << " of the array: ";
        cin >> arr[i];
        i++;
    }

    cout << endl;
    return arr;
}

int main() {
    int idata[10];
    double ddata[10];
    string sdata[10];

    int* intPtr = getInput(idata, 10);
    show<int>(intPtr, 10);
    cout << average<int>(intPtr, 10) << endl;

    double* dblPtr = getInput(ddata, 10);
    show<double>(dblPtr, 10);
    cout << average<double>(dblPtr, 10) << endl;

    string* strPtr = getInput(sdata, 10);
    show<string>(strPtr, 10);

    return 0;
}
