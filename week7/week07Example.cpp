#include <iostream>

using namespace std;

struct Item {
    string name;    // Data Element
    int count;      // Data Element 
    Item *next;     // Pointer to the next item in the list
};

int countItems(Item *head) {
    int count = 0;
    Item *temp = head;   // Copy the head's value (an address)
                            // EX: head = 0x7ffebc0a3a00
                            // temp = 0x7ffebc0a3a00

    while (temp != NULL) {          // While the current item is not NULL because the last item's next is NULL
        count++;                    // Increment the count
        temp = temp->next;          // Move to the next item
    }

    return count;
}

void show(Item *head) {
    Item *temp = head;

    while (temp != NULL) {
        cout << temp->name << " (" << temp->count << ")" << endl;
        temp = temp->next;
    }
}

bool isStringInList(string str, Item *head) {
    Item *temp = head;
    while (temp != NULL) {
        if (temp->name == str) {
            return true;
        } else {
           temp = temp->next;  
        }
    }
    return false;
}

void setCounts(Item *head, int num) {
    Item *temp = head;
    while (temp != NULL) {
        temp->count = num;
        temp = temp->next;
    }
}

int main() {
    Item item1 {"bacon", NULL};
    Item item2 {"eggs", NULL};
    Item item3 {"chair", NULL};
    Item item4 {"soap", NULL};
    Item item5 {"airplane", NULL};

    Item *head;     // Head points to nothing

    head = &item1;  // Head now points to item1

    cout << head->name << endl;  // bacon
    cout << countItems(head) << endl;   // 1

    item1.next = &item2;    // item1 now points to item2
    cout << countItems(head) << endl;   // 2

    item2.next = &item3;    // item2 now points to item3
    cout << countItems(head) << endl;   // 3

    item3.next = &item4;    // item3 now points to item4
    cout << countItems(head) << endl;   // 4

    item4.next = &item5;    // item4 now points to item5
    cout << countItems(head) << endl;   // 5

    // FINAL CHALLENGE 🚨
    // Set all counts to 1
    setCounts(head, 1);

    // CHALLENGE: Show the item names
    show(head); // DONE :D

    // Challenge 2: Ask user to enter a string
    // See if the string is in the list
    string s;
    cout << "Enter a string in the node: ";
    cin >> s;
    bool result = isStringInList(s, head);
    cout << "\n" << result << endl;
    // DONE :D

    return 0;
}
