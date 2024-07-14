#include <iostream>
using namespace std;

struct Window {
    string appname;
    Window *next;
    Window *prev;
};

class WindowManager {
    private:
        Window *current;
        Window *dummy;

        Window * create()   {
            Window * newnode;
            try {
                newnode = new Window;
            } catch (bad_alloc) {
                newnode = NULL;
            }
            return newnode;
        }

        void deallocate() {
            Window *temp = dummy->next;

            while (temp != dummy) {
                Window *next = temp->next;
                delete temp;
                temp = next;
            }
        }
    public:
        ~WindowManager() {
            deallocate();
            dummy = NULL;
        }

        WindowManager() {
            dummy = create();
            dummy->next = dummy;
            dummy->prev = dummy;

            dummy->appname = "";
        }

        void startApp(string name) {
            Window *newnode = create();
            newnode->appname = name;
            
            newnode->next = dummy;
            newnode->prev = dummy->prev;
            dummy->prev->next = newnode;
            dummy->prev = newnode;

            current = newnode;
        }

        string getCurrent() {
            if (current == NULL) {
                return "";
            }

            return current->appname;
        }

        Window *findApp(string name) {
            Window *temp = dummy->next;

            while (temp != dummy) {
                if (temp->appname == name) {
                    return temp;
                }
                temp = temp->next;
            }

            return NULL;
        }

        bool closeApp(string name) {
            Window *currNode = findApp(name);
            
            if (currNode != NULL) {
                if (currNode == current) {
                    current = currNode->next; 
                }
                currNode->prev->next = currNode->next;
                currNode->next->prev = currNode->prev;
                delete currNode;
                return true;
            } else {
                return false;
            }
        }

        string next() {
            if (current == NULL) {
                return "";
            }

            current = current->next;
            return current->appname;
        }

        string prev() {
            if (current == NULL) {
                return "";
            }

            current = current->prev;
            return current->appname;
        }

        void print() {
            Window *temp = dummy->next;

            while (temp != dummy) {
                cout << temp->appname << endl;
                temp = temp->next;
            }
        }
};


int main()
{
    WindowManager winman;

    // simulate some apps running
    winman.startApp("Microsoft Word");
    winman.startApp("Firefox");
    winman.startApp("Halo");
    winman.startApp("Calculator");

    winman.print();

    // at this point, Calculator is the last app launched
    // and should be the value of current in winman
    int action;
    do {
        cout << "1 - Launch new app" << endl;
        cout << "2 - Close current app" << endl;
        cout << "3 - Find app, then close it" << endl;
        cout << "4 - Go to next app" << endl;
        cout << "5 - Go to previous app" << endl;
        cout << "6 - Print all apps" << endl;
        cout << "7 - Show current app" << endl;
        cout << "0 - Shutdown" << endl;
        cout << "--------------------------" << endl;
        cin >> action;

        // fill in the rest of the necessary code to perform 
        // menu actions
        switch(action) {
            case 1: {
                string appname;
                cout << "Enter app name: ";
                cin >> appname;
                winman.startApp(appname);
                break;
            }
            case 2: {
                cout << "Closing current app..." << endl;
                winman.closeApp(winman.getCurrent());
                break;
            }
            case 3: {
                string appname;
                cout << "Enter app name: ";
                cin >> appname;
                if (winman.closeApp(appname)) {
                    cout << "App closed successfully" << endl;
                } else {
                    cout << "App not found" << endl;
                }
                break;
            }
            case 4: {
                cout << "Going to next app..." << endl;
                cout << "Current app: " << winman.next() << endl;
                break;
            }
            case 5: {
                cout << "Going to previous app..." << endl;
                cout << "Current app: " << winman.prev() << endl;
                break;
            } 
            case 6: {
                cout << "Printing all apps..." << endl;
                winman.print();
                break;
            }
            case 7: {
                cout << "Current app: " << winman.getCurrent() << endl;
                break;
            }
            case 0: {
                break;
            }
            default: {
                cout << "Invalid action" << endl;
            }
        }
    } while (action != 0);

    cout << "Shutting down..." << endl;

    return 0;
}
