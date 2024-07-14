#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

int main() {
    Node *head = NULL;

    Node *node1 = new Node();
    head = node1;
    node1->data = 1;
    Node *node2 = new Node();
    node2->data = 2;
    Node *node3 = new Node();
    node3->data = 3;

    node1->next = node2;
    node2->next = node3;

    Node *temp1 = head;
    while (temp1 != NULL) {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    node3 = NULL;

    Node *temp = head->next;
    head->next = temp->next;
    delete temp;

    cout << "\n\n" << endl;

    Node *temp2 = head;
    while (temp2 != NULL) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }


    return 0;
}