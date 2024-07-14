#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class CircDoubLiList {
    private:
        Node *head;
        Node *tail;
    public:
        CircDoubLiList() : head(nullptr), tail(nullptr) {}
        void addNodeToFront(int data) {
            Node *newNode = new Node();
            newNode->data = data;

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
                newNode->next = newNode;
                newNode->prev = newNode;
            } else {
                newNode->next = head;
                newNode->prev = tail;
                head->prev = newNode;
                tail->next = newNode;
                head = newNode;
            }
        }

        void addNodeToBack(int data) {
            Node *newNode = new Node();
            newNode->data = data;

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
                newNode->next = newNode;
                newNode->prev = newNode;
            } else {
                newNode->prev = tail;
                newNode->next = head;
                head->prev = newNode;
                tail->next = newNode;
                tail = newNode;
            }
        }
        void display() {
            Node *temp = new Node();
            temp = head;

            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while(temp != head);
            cout << endl;
        }

        void displayReverse() {
            Node *temp = new Node();
            temp = tail;
            do {
                cout << temp->data << " ";
                temp = temp->prev;
            } while (temp != tail);
            cout << endl;
        }

        bool find(int data) {
            Node *temp = new Node();
            temp = head;

            do {
                if (temp->data == data) {
                    return true;
                } 
                temp = temp->next;
            } while (temp != head);

            return false;
        } 

        void removeNodeFromFront() {
            if (head == nullptr) return;

            if (head->next == head) {
                delete head;
                head = tail = nullptr;
                return;
            }

            Node *temp = new Node();
            temp = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }

        void removeNodeFromBack() {
            if (head == nullptr) return;

            if (head == head->next) {
                delete tail;
                head = tail = nullptr;
                return;
            }
        
            Node *temp = new Node();
            temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }

        void removeNodeAtPos(int data) {
            if (head == nullptr) return; 

            Node* temp = head;
            while (temp->next != head) {
                if (temp->data == data) {
                    // Node with specified data found, remove it from the list
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head) {
                        head = temp->next;
                    }
                    delete temp;
                    return;
                }
                temp = temp->next;
            }

            // Check the last node (tail) outside the loop
            if (temp->data == data) {
                temp->prev->next = head; // Update the next pointer of the last node
                head->prev = temp->prev; // Update the prev pointer of the head
                delete temp;
                return;
            }

            cout << "Node with data " << data << " not found." << endl;
        }
};

int main() {
    CircDoubLiList list;
    for (int i = 10; i >= 0; i--) list.addNodeToFront(i);
    list.display();

    list.removeNodeFromFront();
    list.display();
    list.removeNodeFromBack();
    list.display();

    int x;
    cout << "Remove Node at: ";
    cin >> x;

    list.removeNodeAtPos(x);
    list.displayReverse();

    return 0;
}