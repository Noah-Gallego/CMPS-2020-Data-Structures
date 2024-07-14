#include <iostream>
using namespace std;

// CIRCULAR DOUBLY LINKED LIST WITH DUMMY NODE
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class CircularDoublyLinkedList {
private:
    Node* dummyNode;
public:
    CircularDoublyLinkedList() {
        dummyNode = new Node();
        dummyNode->prev = dummyNode;
        dummyNode->next = dummyNode;
    }

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = dummyNode->prev;
        newNode->next = dummyNode;
        dummyNode->prev->next = newNode;
        dummyNode->prev = newNode;
    }

    void remove(int data) {
        Node* current = dummyNode->next;
        while (current != dummyNode) {
            if (current->data == data) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void display() {
        Node* current = dummyNode->next;
        while (current != dummyNode) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();
    list.remove(20);
    list.display();
    return 0;
}