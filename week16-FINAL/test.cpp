// Make a median of three sort on the array {31, 4, 15, 9, 26, 5, 35, 8, 97} and print every step of the partioning process
// Expected output:

// 31 4 15 9 26 5 35 8 97
// 15 4 8 9 26 5 31 35 97
// 8 4 5 9 26 15 31 35 97

#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int median_of_three(std::vector<int> &arr, int low, int high) {
    int mid = (low + high) / 2;
    if (arr[low] > arr[mid]) {
        std::swap(arr[low], arr[mid]);
    }
    if (arr[mid] > arr[high]) {
        std::swap(arr[mid], arr[high]);
    }
    if (arr[low] > arr[mid]) {
        std::swap(arr[low], arr[mid]);
    }
    return mid;
}

int partition(std::vector<int> &arr, int low, int high) {
    int pivot = median_of_three(arr, low, high);
    std::swap(arr[pivot], arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < arr[high]) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        print(arr);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    std::vector<int> arr = {31, 4, 15, 9, 26, 5, 35, 8, 97};
    print(arr);
    quicksort(arr, 0, arr.size() - 1);
    return 0;
}