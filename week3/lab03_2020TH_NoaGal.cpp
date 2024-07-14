#include <iostream>

using namespace std;

class Control {
    protected:
        string text;
    public:
        Control(string _t) : text(_t) {};
};

class Checkbox : public Control {
    private:
        bool checked;
    public:
        Checkbox(string _t, bool _c) : Control(_t) {
            checked = _c;
        };

        string display() {
            return checked ? text += ": [X]" : text += ": [ ]";
        }
};

class Textbox : public Control {
    private:
        string caption;
    public:
        Textbox(string _t, string _c) : Control(_t) {
            caption = _c;
        }

        string display() {
            return caption == "" ? text += ": N/A" : text + ": " + caption;
        }
};

int main() {
    Textbox t1("First Name", "Marco");
    Textbox t2("Middle Name", "");
    Textbox t3("Last Name", "Polo");

    Checkbox c1("Employed", true);
    Checkbox c2("Student", false);

    cout << t1.display() << endl;
    cout << t2.display() << endl;
    cout << t3.display() << endl;
    cout << endl; 
    cout << c1.display() << endl;
    cout << c2.display() << endl;

    return 0;
}