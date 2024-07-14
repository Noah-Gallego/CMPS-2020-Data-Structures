#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    private:
        Node *head = new Node();

        void deallocate() {
            // COMPLETE
        }
    public:
        LinkedList() : head(nullptr) {}

        ~LinkedList() {
            deallocate();
            head = nullptr;
        }

        void addToFront(int data) {
            // Prepare a new node
            Node *newNode = new Node();
            newNode->data = data;

            // Put node in the front of head
            newNode->next = head;

            // Move head of the list to point to the newNode
            head = newNode;
        }

        void addToBack(int data) {
            // Prepare a new node
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;

            // If linked list is empty, newNode will be the head node
            if (head == nullptr) {
                head = newNode;
            } 

            // Find the last node
            Node *last = new Node();
            last = head;
            while (last->next != nullptr) {
                last = last->next;
            }

            // Insert newNode after last node (at the end)
            last->next = newNode;
        }

        void insertAfterNode(int currNodeData, int dataNewNode) {
            // Initialize found
            bool found = false;

            // CREATE NEWNODE
            Node *newNode = new Node();

            // CREATE TEMP
            Node *temp = head;

            //FIND NODE
            while (temp != nullptr) {
                if (temp->data == currNodeData) {
                    found = true;
                    break;
                }
                temp = temp->next;
            }

            // ADD NODE
            if (found) {
                newNode->data = dataNewNode;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        string *findNode(int data) {
            Node* temp = head;
            int count = 0;
            bool found = false; 

            while (temp != nullptr) {
                count++;
                if (temp->data == data) { 
                    found = true;
                    break;
                }
                temp = temp->next;
            }

            if (found) {
                return new string("Node found at position " + to_string(count) + ". Data = " + to_string(data));
            } else {
                return new string("Node not found");
            }
        }

        void removeFromBack() {
            // Create temp
            Node *temp = head;

            // Find Last Node
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }

            // Delete Last Node
            delete temp->next;
            temp->next = nullptr;
        }

        void removeFromFront() {
            // Create temp
            Node *temp = head;

            // Move head to next node
            head = head->next;

            // Delete temp
            delete temp;
        }

        void show(LinkedList l) {
            Node *temp = l.head;
            while (temp != nullptr) {
                cout << temp->data << ", ";
                temp = temp->next;
            }
        }
};

int main() {
    //Initializing List
    LinkedList list;

    for (int i = 5; i >= 1; i--) {
        list.addToFront(i);
    }

    list.show(list);

    // OPTIONS
    int choice;
    cout << "Would you like to add a node to the front or the back?" << endl;
    cout << "1 Add to front" << endl;
    cout << "2 Add to Back" << endl;
    cout << "3 Find a Node" << endl;
    cout << "4 Add to back of given Node" << endl;
    cout << "5 Show the Whole List" << endl;
    cout << "6 Remove from Back" << endl;
    cout << "7 Remove from Front" << endl;


    cin >> choice;

    switch(choice) {
        case 1:
            int add;
            cout << "What would you like to add to the front? ";
            cin >> add;
            list.addToFront(add);
            list.show(list);
            break;
        case 2:
            int addBack;
            cout << "What would you like to add to the back? ";
            cin >> addBack;
            list.addToBack(addBack);
            list.show(list);
            break;
        case 3:
            int exist;
            cout << "What value would you like to see exists? ";
            cin >> exist;
            list.findNode(exist);
            list.show(list);
            break;
        case 4:
            int currNode;
            int NewNodeVal;
            cout << "Enter a node you would like to append something to: ";
            cin >> currNode;
            cout << "\n Enter the value for the New Node: ";
            cin >> NewNodeVal;
            list.insertAfterNode(currNode, NewNodeVal);

            list.show(list);
            break;
        case 5:
            list.show(list);
            break;
        case 6:
            list.removeFromBack();
            list.show(list);
            break;
        case 7:
            list.removeFromFront();
            list.show(list);
            break;
        default:
            cout << "Enter a valid option!" << endl;
    }

    return 0;
}