#include <iostream>

using namespace std;

struct Location {
    string name;
    string url;
};

class Stack {
    private:
        Location nodes[100];
        int count = 0;
    public:
        bool push(string name, string url) {
            for (int i = count; i > 0; i--) {
                nodes[i] = nodes[i - 1];
            }
            count++;

            nodes[0].name = name;
            nodes[0].url = url;

            return count < 100;
        }

        string pop() {
            string top = "";
            if (count < 0) {
                return top;
            } else {
                top = nodes[0].name;
                for (int i = count; i < count; i++) {
                    nodes[i] = nodes[i - 1];
                }
                count--;
            }

            return nodes[count].name;
        }

        friend void show(Stack &s);
};

void show(Stack &S) {
    for (int i = 0; i < S.count; i++) {
        cout << S.nodes[i].name << " ";
        if (i == S.count - 1) cout << endl;
    }
}

int main() {
    Stack browser;

    // simulate a browser history
    browser.push("Google", "//google.com");
    browser.push("Amazon", "//amazon.com");
    browser.push("LinkedIn", "//LinkedIn.com");
    browser.push("Reddit", "//reddit.com");  

    show(browser);   // this should show the entire history

    // simulate clicking Back button
    string top = browser.pop();
    if (top != "")
    cout << endl << "Clicked back from " << top << endl;
    show(browser);

    // simulate clicking Back button  
    top = browser.pop();
    if (top != "")
    cout << endl << "Clicked back from " << top << endl;
    show(browser);

    // simulate clicking Back button
    top = browser.pop();
    if (top != "")
    cout << endl << "Clicked back from " << top << endl;
    show(browser);

    return 0;
}