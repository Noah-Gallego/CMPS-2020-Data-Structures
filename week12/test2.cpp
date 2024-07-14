#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;   
};

class LinkedList {
    private:
        Node *head = nullptr;
        Node *tail = nullptr;

    public:
        ~LinkedList() {
            while (head != nullptr) {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

};

int main() {
    
    return 0;
}
