#include <iostream>
#include <string>

using namespace std;

class A {
    private:
        string name;
        int *data;
    public:
        A (string n) {
            name = n;
            data = new int;
        }
            // Static - Given scope, return to memory when unused
        ~A() {
            cout << name << " destroyed" << endl;
        }
};

int main() {
    int x;
    A a1("A1");
    A a2("A2");
    A a3("A3");
    A *a4 = new A("A4");

    // Used a4 for something in the code
    // What would that look like on the call stack/heap?

    delete a4;

    cout << "Last line in main" << endl;

    return 0;
}