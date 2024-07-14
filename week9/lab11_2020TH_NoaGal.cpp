#include <iostream>

using namespace std;

class RingBuffer {
    private:
        int size;
        string *names;
        int front;
        int back;
    public:
        RingBuffer(int size) {
            this->size = size;
            names = new string[size];
            front = 0;
            back = 0;
        }

        ~RingBuffer() {
            delete[] names;
        }

        bool isFull() {
            return (back + 1) % size == front;
        }

        bool enqueue(string name) {
            if (isFull()) {
                return false;
            }
            names[back] = name;
            back = (back + 1) % size;
            return true;
        }

        string dequeue() {
            if (!isFull()) {
                return "";
            }
            front = (front + 1) % size;
            return names[front];
        }

        void friend show(RingBuffer &rb);
};

void show(RingBuffer &rb) {
    // A for loop makes it easier for me :)
    for (int i = rb.front; i != rb.back; i = (i + 1) % rb.size) {
        cout << rb.names[i] << " ";
    }
    cout << endl;
};

int main() {
    RingBuffer buffer(4);
    char action;
    string name = "";
    bool added;

    do {
        cout << "e - Enqueue" << endl;
        cout << "d - Dequeue" << endl;
        cout << "q - Quit" << endl;
        cout << "Action: ";
        cin >> action;

        switch(action) {
            case 'e':
                cout << "Name: ";
                cin >> name;
                added = buffer.enqueue(name);
                if (added) {
                    cout << "Added " << name << endl;
                } else {
                    cout << name << " was not added. Queue full" << endl;
                }
                break;
            case 'd':
                name = buffer.dequeue();
                if (name == "") {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Dequeued " << name << endl;
                }
                break;
        }

        show(buffer);
        cout << "-------------" << endl;

    } while (action != 'q');
    return 0;
}