#include <iostream> 
#include <string>
using namespace std;

// FROM PREV LAB - BUBBLE SORT
void sort(string items[], int size) {
    for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (items[i] > items[j]) {
        string temp = items[i];
        items[i] = items[j];
        items[j] = temp;
      }
    }
  }
}

// CURRENT LAB
int findItemLinear(string items[], string item, int size) {
    for (int i = 0; i < size; i++) {
        if (items[i] == item) return i;
    }
    return -1;
}

int findItemBinary(string items[], string item, int size) {
    int start = 0, end = size - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (items[mid] == item) {
            return mid;
        } else if (items[mid] < item) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int findMatches(string items[], string pattern, int size, string matches[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        std::size_t found = items[i].find(pattern);
        if (found != std::string::npos) {
            matches[count] = items[i];
            count++;
        } else {
            continue;
        }
    }
    return count;
} 

void showArray(string items[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            cout << items[i] << ", ";
        } else {
            cout << items[i];
        }
    }
    cout << "]" << endl;
}

int main() {
    string text[25] = { "winter", "radius", "arthritis", "sponge", "rotation", "brandy", "radium", "crank", "ginger", "ankle", "cooler", "cranium", "potato", "receipt", "keratin", "stool", "termite", "dynamite", "singing", "banker", "thrifty", "longer", "tattoo", "rations", "being"};
    
    sort(text, 25);  // Sorting the array for binary search to work

    cout << "1- Search for a word using linear" << endl;
    cout << "2- Search for a word using binary" << endl;
    cout << "3- Search for a partial string" << endl;

    int choice;
    cout << "Action: ";
    cin >> choice;

    string searchTerm;
    switch (choice) {
        case 1:
            cout << "Enter string: ";
            cin >> searchTerm;
            if (findItemLinear(text, searchTerm, 25) != -1) {
                cout << "Found " << searchTerm << endl;
            } else {
                cout << searchTerm << " was not found" << endl;
            }
            break;
        case 2:
            cout << "Enter string: ";
            cin >> searchTerm;
            if (findItemBinary(text, searchTerm, 25) != -1) {
                cout << "Found " << searchTerm << endl;
            } else {
                cout << searchTerm << " was not found" << endl;
            }
            break;
        case 3:
            cout << "Enter string: ";
            cin >> searchTerm;
            string matches[25] = {""};
            int newSize = findMatches(text, searchTerm, 25, matches);
            showArray(matches, newSize);
            break;
    }

    return 0;
}