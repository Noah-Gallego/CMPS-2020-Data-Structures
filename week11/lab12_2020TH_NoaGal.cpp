#include <iostream>
using namespace std;

struct DataNode {
    string value;
    DataNode *next;
    DataNode *prev;
};

class Deque {
protected:
    DataNode *head = NULL;
    DataNode *tail = NULL;

    DataNode * create() {
        DataNode *newnode;
        try {
            newnode = new DataNode;
            newnode->prev = NULL;
            newnode->next = NULL;
        } catch (bad_alloc) {
            newnode = NULL;
        }
        return newnode;
    }

    ~Deque() {
        while (head != NULL) {
            DataNode *temp = head;
            head = head->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    void addToHead(string value) {
        DataNode *newNode = create();
        newNode->value = value;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    string removeFromTail() {
        string value = "";
        if (tail != NULL) {
            if (tail == head) {
                value = tail->value;
                delete tail;
                head = NULL;
                tail = NULL;
            } else {
                DataNode *temp = tail;
                value = temp->value;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }
        return value;
    }

    void addToTail(string value) {
        DataNode *newNode = create();
        newNode->value = value;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    string removeFromHead() {
        string value = "";
        if (head != NULL) {
            if (head == tail) {
                value = head->value;
                delete head;
                head = NULL;
                tail = NULL;
            } else {
                DataNode *temp = head;
                value = temp->value;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }
        return value;
    }
public:
    friend void show(Deque &Q) {
        DataNode *temp = Q.head;
        while (temp != NULL) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

class Queue : public Deque {
public:
    Queue & enqueue(string value) {
        addToTail(value);
        return *this;
    }
    string dequeue() {
        return removeFromHead();
    }
};

class Stack : public Deque {
public:
    Stack &push(string value) {
        addToHead(value);
        return *this;
    }
    string pop() {
        return removeFromHead();
    }
};

int main() {
    Queue q;

    q.enqueue("Heaven").enqueue("Hell").enqueue("Limbo");
    show(q);
    // additional driver code
    cout << "DEQUEUE: " << q.dequeue() << endl;
    show(q);

    Stack s;

    s.push("Humpty").push("Dumpty");
    show(s);
    s.pop();
    show(s);
    // additional driver code 
    return 0;
}
