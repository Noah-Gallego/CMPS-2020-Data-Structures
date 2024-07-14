#include <iostream>

using namespace std;

struct JobNode {
    string name;
    JobNode *next;
};

class Queue {
    private:
        JobNode *head;
        int count = 0;

        void deallocate() {
            JobNode *temp;
            while (head != NULL) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

    public:
        Queue() {
            head = NULL;
        }

        ~Queue() {
            deallocate();
            head = NULL;
        }

        JobNode *create() {
            JobNode *newnode;
            try {
                newnode = new JobNode;
            } catch (bad_alloc) {
                newnode = NULL;
            }
            return newnode;
        }

        bool enqueue(string name) {
            JobNode *newnode = create();
            count++;

            if (newnode == NULL) {
                return false; 
            }
            newnode->name = name;

            if (head == NULL) {
                head = newnode;
                newnode->next = NULL;
            } else {
                newnode->next = head;
                head = newnode;
            }

            return true;
        }

        string dequeue() {
            if (head == NULL) {
                return "Empty List\n";
            } else {
                JobNode *t1, *t2;
                t1 = head;
                t2 = NULL;
                while (t1->next != NULL) {
                    t2 = t1;
                    t1 = t1->next;
                }            
                
                string name = t1->name; 
                if (t2 == NULL) {
                    head = NULL;
                } else {
                    t2->next = NULL;
                }
                count--;
                delete t1;
                return name; 
            }
            
        }

        friend void show(Queue &Q);
};

void show(Queue &Q) {
    for (int i = 0; i < Q.count; i++) {
        JobNode *temp = Q.head;
        for (int j = 0; j < Q.count - i - 1; j++) {
            temp = temp->next;
        }
        cout << temp->name << endl;
    }
}

int main() {
    Queue spooler;

    // simulate a printer spooler
    spooler.enqueue("Comm100 Paper.docx");
    spooler.enqueue("Fwd: Direct Deposit");
    spooler.enqueue("document(1).doc");
    spooler.enqueue("lab9.cpp");

    cout << "Pending jobs: " << endl;
    show(spooler);   // this shows all jobs

    // simulate the printer completing the jobs
    string oldest;
    do {
        oldest = spooler.dequeue();
        if (oldest != "Empty List\n") { // Check against the correct return value
            cout << "Printing..." << endl;
            cout << oldest << " printed" << endl;

            cout << endl << "Pending jobs:" << endl; 
            show(spooler);     
        }
    } while (oldest != "Empty List\n"); // Check against the correct return value

    cout << "No jobs" << endl;

    return 0;
}
