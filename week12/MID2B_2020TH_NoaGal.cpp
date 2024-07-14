// Noah Gallego
// 04/16/2024

#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node *next;
    Node *prev;
};

class Linked
{
    private:
        Node *head, *tail;
        Node * create(string data)
        {
            try
            {
                Node *newnode = new Node;
                newnode->data = data;
                newnode->next = NULL;
                newnode->prev = NULL;
                return newnode;
            }
            catch (bad_alloc)
            {
                return NULL;
            }
        }
 
       
    public:
        Linked()
        {
            head = NULL;
            tail = NULL;
        }

        void add(string value)
        {
            Node * newnode = create(value);
            if (head == NULL)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                // TODO: add the new node at the tail
                // DO NOT wire up ->prev pointers in this function
                // 3 pts
                tail->next = newnode;
                newnode->next = NULL;
                tail = newnode;
            }
        }

        void linkprev()
        {
            // TODO: This function will wire up the nodes using the ->prev pointer
            // at this point, the entire node has been connected using ->next
            //
            // After this function has been called, then you can use the tail
            // pointer to traverse this list in the reverse direction
            // 4 pts
            Node *currNode = create("");
            currNode = head;
            while (currNode->next != NULL) {
                currNode->next->prev = currNode;
                currNode = currNode->next;
            }
        }
       
       bool find(string value)
        {
            // TODO: return true if value is found in the list. Otherwise, return false
            // 5 pts
            Node *currNode = create(value);
            currNode = head;

            while (currNode != NULL) {
                if (currNode->data == value) {
                    return true;
                }
                currNode = currNode->next;
            }
            return false;
        }

        friend void showreverse(Linked &linked)
        {
            linked.linkprev();

            // TODO: show the list starting from tail
            // traversing in the opposite direction using prev pointer
            //
            // 5 pts
            Node *currNode = linked.create("");
            currNode = linked.tail;
            while (currNode != NULL) {
                cout << currNode->data << " ";
                currNode = currNode->prev;
            }
        }
        
        friend void show(Linked & linked)
        {
            Node * node = linked.head;
            while (node != NULL)
            {
                cout << node->data << " ";
                node = node->next;
            }
            cout << endl;
        }

        ~Linked()
        {
            // deallocate the nodes. You don't need to make a separate deallocate function
            // you can do it all here in the destructor
            // 5 pts
            while (head != NULL) {
                Node *currNode = head;
                head = head->next;
                delete currNode;
            }
            head = NULL;
            tail = NULL;
        }

        void compact()
        {
            // TODO: compact the list by merging pairs of nodes into one
            //       and combining their respective values
            //
            // If there is a left-over node because there is an odd number of nodes,
            // then that node will not be merged. It will remain in the linked list
            // as just another node with its original value. 
            //
            // 10 pts
            Node *currNode = create("");
            currNode = head;
            while (currNode != NULL && currNode->next != NULL) {
                currNode->data += currNode->next->data;
                currNode->next = currNode->next->next;
                currNode = currNode->next;
            }
       }

};

int main()
{
    string value;
    string values[9] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX", "YZ" };
    Linked list;

    // TODO: fill the list with all items from the values array, using the add() function
    // 1 pt
    for (int i = 0; i < 9; i++) {
        list.add(values[i]);
    }

    cout << "Forward: " << endl;
    show(list);
    cout << endl;

    cout << "Reverse: " << endl;
    showreverse(list);
    cout << endl;

    // this will compact the nodes
    // nodes ABC DEF GHI JKL MNO PQR STU VWX YZ will become
    //       ABCDEF GHIJKL MNOPQR STUVWX YZ
    list.compact();

    // show the nodes again to confirm compaction
    show(list);

    // If you want to see another compaction, uncomment below. Should show the list even shorter
    list.compact();
    show(list);

    cout << "Find value: ";
    cin >> value;
    // TODO: display if a particular string is found in the linked list
    //       For example, you should be able to search for GHIJKL
    // 2 pt
    if (list.find(value)) {
        cout << "Value Found!" << endl;
    } else {
        cout << "Value Not Found." << endl;
    }

    return 0;
}
