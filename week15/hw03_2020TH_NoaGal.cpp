#include <iostream>
using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right;
};

void showNode(Node *subtreeroot) {
    if (subtreeroot == NULL) {
        return;
    }
    showNode(subtreeroot->left);
    cout << subtreeroot->value << " ";
    showNode(subtreeroot->right);
}

class BST {
    private:
        int count;
        Node *root;
        Node *create(int value) {
            Node *newNode = new Node();
            newNode->value = value;
            newNode->left = NULL;
            newNode->right = NULL;
            count++;
            return newNode;
        }
        void addNode(Node *subtreeroot, int value) { // Val
            if (subtreeroot->value > value) { // Left
                if (subtreeroot->left == NULL) {
                    subtreeroot->left = create(value);
                } else {
                    addNode(subtreeroot->left, value);
                }
            } else { // Right
                if (subtreeroot->right == NULL) {
                    subtreeroot->right = create(value);
                } else {
                    addNode(subtreeroot->right, value);
                }
            }
        }
        void destroyNode(Node *subtreeroot) {
            if (subtreeroot == NULL) {
                return;
            }
            destroyNode(subtreeroot->left); // Left
            destroyNode(subtreeroot->right); // Right
            delete subtreeroot; // Val
            count--;
        }
    Node* findNode(Node* subtreeroot, int value) {
        if (subtreeroot == NULL || subtreeroot->value == value) {
            return subtreeroot;
        }
        if (value < subtreeroot->value) {
            return findNode(subtreeroot->left, value);
        } else {
            return findNode(subtreeroot->right, value);
        }
    }

    public:
        BST() {
            root = NULL;
            count = 0;
        }
        ~BST() {
            destroyNode(root);
        }
        void add(int item) {
            if (root == NULL) {
                root = create(item);
            } else {
                addNode(root, item);
            }
        }

        friend void show(BST &bst) {
            showNode(bst.root);
        }

        int getCount() {
            return count;
        }

        bool find(int value) {
            return findNode(root, value) != NULL;
        }

        bool deleteNode(int value) {
            bool found = false;
            Node *temp = root;
            Node *parent = NULL;

            // Find the node to delete and identify its parent
            while (!found && temp != NULL) {
                if (value == temp->value) {
                    found = true;
                } else if (value < temp->value) {
                    parent = temp;
                    temp = temp->left;
                } else {
                    parent = temp;
                    temp = temp->right;
                }
            }

            if (found) {
                if (temp->left == NULL && temp->right == NULL) { // Leaf node
                    if (parent == NULL) { // If root
                        root = NULL;
                    } else if (parent->left == temp) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                    delete temp;
                } else if (temp->left == NULL || temp->right == NULL) { // Node with one child
                    Node *child = (temp->left != NULL) ? temp->left : temp->right;
                    if (parent == NULL) { // If root
                        root = child;
                    } else if (parent->left == temp) {
                        parent->left = child;
                    } else {
                        parent->right = child;
                    }
                    delete temp;
                } else { // Node with two children
                    Node *replacement = temp->right;
                    while (replacement->left != NULL) {
                        parent = replacement;
                        replacement = replacement->left;
                    }
                    temp->value = replacement->value;
                    if (parent->left == replacement) {
                        parent->left = replacement->right;
                    } else {
                        parent->right = replacement->right;
                    }
                    delete replacement;
                }
                count--;
                return true;
            }
            return false;
        }
};

int main() {
    BST bst;
    int values[25] = {23, 117, 45, 19, 7, 13, 17, 40, 9, 11, 93, 49, 35, 8, 3, 10, 22, 77, 16, 6, 51, 57, 55, 90, 31};

    for (int i : values) {
        bst.add(i);
    }

    show(bst); 

    int searchValue;
    cout << "\nEnter a number to search: ";
    cin >> searchValue;

    bool found = bst.find(searchValue);
    if (found) {
        cout << "Value " << searchValue << " found in the tree." << endl;
        char response;
        cout << "Do you want to delete it? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y') {
            bool deleted = bst.deleteNode(searchValue);
            if (deleted) {
                cout << "Value " << searchValue << " deleted from the tree." << endl;
                show(bst); 
            } else {
                cout << "Error occurred while deleting the value." << endl;
            }
        }
    } else {
        cout << "Value " << searchValue << " not found in the tree." << endl;
    }

    cout << "Number of nodes: " << bst.getCount() << endl;

    return 0;
}