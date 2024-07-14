#include <iostream>

using namespace std;

template <typename T, typename U>
class Something {
    private:
        T t1;
        U value;
        T data;
    public:
        
}

// TEMPLATE SPECIALIZATION EXAMPLE
struct Building {
    string name;
    int floors;
};

template <typename Type>
Type larger(Type a, Type b) {
    return (a > b ? a : b);
}

// Template specialization
template <> Building larger(Building a, Building b) {
    return a.floors > b.floors ? a : b;
}

int main() {
    cout << larger<int>(4, 9) << endl;
    cout << larger<double>(3.14159, 2.38743) << endl;
    cout << larger<string>("Hi", "Hello") << endl;

    Building b1 {"Sci III", 3};
    Building b2 {"BofA", 13};

    Building lb = larger<Building>(b1, b2);
    cout << lb.name << endl;

    Something<char, int>s1;
    s1.fn()

    return 0;
}