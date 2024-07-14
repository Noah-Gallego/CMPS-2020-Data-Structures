#include <iostream>

using namespace std;

int get_int_from_user(string prompt, int minLimit, int maxLimit);
int get_int_from_user(string prompt);

int main() {
    int num1, num2;

    num1 = get_int_from_user("Enter a number: ", 5, 10); 
    num2 = get_int_from_user("Enter a second number: ", -1, 9);
    
    cout << num1 << " " << num2 << endl;

    return 0;    
}

int get_int_from_user(string prompt, int minLimit, int maxLimit) {
    int input;

    do {
        cout << prompt;
        cin >> input;
    } while (input > minLimit || input < maxLimit);
        
    return input;
}

int get_int_from_user(string prompt) {
    int input;
    cout << prompt;
    cin >> input;

    return input;
}
