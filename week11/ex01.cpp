#include <iostream>
using namespace std;

class Person {
    private:
        string first, last;
    public:
        Person &setFirst(string f) {
            first = f;
            return *this;
            // Pointer to itself
        }

        Person &setLast(string l) {
            last = l;
            return *this;
        }

        string get() {
            return first + " " + last;
        }
};

int main() {
    // Fluent Programming
    Person p;
    string final = p.setFirst("John").setLast("Doe").get();

    cout << final << endl;

    return 0;
}