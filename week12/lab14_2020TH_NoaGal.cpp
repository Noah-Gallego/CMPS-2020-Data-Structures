#include <iostream>
#include <fstream>
// using namespace std; Causing errors with 'max'??

int hash[172820] = {0};
int collisions[320] = {0};

int calcHash(std::string word) {
    int charVal[word.size()];
    int sum = 0;

    for (int i = 0; i < word.size(); i++) {
        charVal[i] = word[i] - 'a' + 1;
    }

    for (int i : charVal) {
        sum += i;
    }

    return sum;
}

void readWords() {
    std::ifstream fin;
    fin.open("enable1.txt");
    std::string word;
    int i = 0;
    while (fin >> word) {
        hash[i] = calcHash(word);
        i++;
    }
    fin.close();
}

int main() {
    // Populate Array
    readWords();
    
    for (int i = 0; i < 172820; i++) {
        // Takes hashed value and with each access, 
        // increments collisions at that
        // index by 1
        collisions[hash[i] % 320]++;
    }

    // Print Number of Collisions per line
    for (int i : collisions) {
        std::cout << i << std::endl;
    }

    // Find max and print the value
    int max = 0;
    for (int i = 0; i < 320; i++) {
        if (collisions[i] > max) {
            max = collisions[i];
        }
    }

    std::cout << "Max collisions: " << max << std::endl;
    
    return 0;
}
