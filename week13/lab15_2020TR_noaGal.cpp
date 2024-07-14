#include <iostream>

using namespace std;

struct Location {
    string name;
    string url;
};

struct VisitNode {
    Location loc;
    VisitNode* next;
};

class Stack {
    private:
        VisitNode *head;

        // Recursive Deallocate
        void deallocate(VisitNode *node) {
            if (node == NULL) {
                return;
            }

            deallocate(node->next);
            delete node;
        }

        VisitNode *create() {
            VisitNode *newNode;
            try {
                newNode = new VisitNode;
            } catch (bad_alloc) {
                newNode = NULL;
            }

            return newNode;
        };
    public:
        Stack() {
            head = NULL;
        }

        ~Stack() {
            deallocate(head);
            head = NULL;
        }

        bool push(string name, string url) {
            VisitNode *newNode = create();
            newNode->loc.name = name;
            newNode->loc.url = url;
            if (head == NULL) { // empty
                head = newNode;
                newNode = NULL;
            } else {
                newNode->next = head;
                head = newNode;
            }

            return newNode == NULL ? false : true;
        }

        string pop() {
            if (head != NULL) {
                VisitNode *temp = head;
                head = head->next;
                string name = temp->loc.name;
                delete temp;
                return name;
            } else {
                return "";
            }
        }

        friend void show(Stack &s);
};

// Rewritten showNode function
void showNode(VisitNode *node) {
    if (node != NULL) {
        cout << node->loc.name << endl;
    } else {
        return;
    }

    showNode(node->next);
}

void show(Stack &s) {
    showNode(s.head);
};
 
int main() {
    Stack browser;

    // simulate a browser history
    browser.push("Google", "//google.com");
    browser.push("Amazon", "//amazon.com");
    browser.push("LinkedIn", "//LinkedIn.com");
    browser.push("Reddit", "//reddit.com");  

    show(browser);   // this should show the entire history

    // // simulate clicking Back button
    // string top = browser.pop();
    // if (top != "")
    // cout << endl << "Clicked back from " << top << endl;
    // show(browser);

    // // simulate clicking Back button  
    // top = browser.pop();
    // if (top != "")
    // cout << endl << "Clicked back from " << top << endl;
    // show(browser);

    // // simulate clicking Back button
    // top = browser.pop();
    // if (top != "")
    // cout << endl << "Clicked back from " << top << endl;
    // show(browser);

    return 0;
};