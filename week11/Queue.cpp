#include <iostream>
using namespace std;

struct DataNode {
    string value;
    DataNode *next;
    DataNode *prev;
};

class Deque {
    protected:
        DataNode *head = nullptr;
        DataNode *tail = nullptr;

        DataNode *create() {
            DataNode *newNode;
            try {
                newNode = new DataNode();
                newNode->prev = nullptr;
                newNode->next = nullptr;
            } catch(bad_alloc) {
                newNode = nullptr;
            }

            return newNode;
        }

        void deallocate() {
            DataNode *temp = head;
            while (temp != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void addToHead(string value) {
            DataNode *newNode = create();
            newNode->value = value;

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        string removeFromTail() {
            DataNode *temp = create();
            string val;
            temp = head;
            if (head != nullptr) {
                while (temp != nullptr) {
                    temp = temp->next;
                }
                val = temp->value;
                temp->prev = nullptr;
                delete temp;
                return val;
            } else {
                return "";
            }
        }

        void addToTail(string value) {
            DataNode *newNode = create();
            newNode->value = value;

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        string removeFromHead() {
            DataNode *temp = create();
            string val;
            temp = head;
            if (head != nullptr) {
                val = temp->value;
                head = head->next;
                head->prev = nullptr;
                delete temp;
                return val;
            } else {
                return "";
            }
        }

    public:
        ~Deque() {
            deallocate();
            head = nullptr;
            tail = nullptr;
        }

        friend void show(Deque &deque) {
            DataNode *temp = deque.head;
            while (temp != nullptr) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

class Queue : public Deque {
    public:
        Queue &enque(string value) {
            addToTail(value);
            return *this;
        }

        Queue &deque() {
            removeFromHead();
            return *this;
        }
};

class Stack : public Deque {
    public:
        Stack &push(string value) {
            addToHead(value);
            return *this;
        }

        Stack &pop() {
            removeFromHead();
            return *this;
        }
};


int main() {
    Queue queue;
    queue.denque("A").enque("B").enque("C").enque("D");
    show(queue);

    queue.deque();
    show(queue);

    Stack stack;
    stack.push("A").push("B").push("C").push("D");
    show(stack);

    stack.pop();
    show(stack);
    
    return 0;
}