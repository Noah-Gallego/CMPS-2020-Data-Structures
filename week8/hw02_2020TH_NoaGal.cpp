#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

template <typename T>
struct ValueNode
{
    T val;
    ValueNode * next;
};

template <typename T>
class Stack
{
    private:
        ValueNode <T> * head;
        ValueNode <T> * create(T newval)
        {
            ValueNode <T> * newnode;
            try
            {
                newnode = new ValueNode<T>;
                newnode->val = newval;
            }
            catch (bad_alloc)
            {
                newnode = NULL;
            }
            return newnode;
        }
    public:
        Stack () 
        {
            head = NULL;
        }

        void push(T newvalue)
        {
            ValueNode <T> * item = create(newvalue);
            if (head == NULL)
            {
                head = item;
                item->next = NULL;
            }
            else
            {
                ValueNode <T> * temp = head;
                head = item;
                item->next = temp;
            }
        }

        bool pop(T & popped)
        {
            ValueNode <T> * temp = head;
            bool success = false;
            if (temp != NULL)
            {
                popped = temp->val;
                head = temp->next;
                delete temp;
                success = true;
            }

            return success;
        }

        ~Stack() {
            ValueNode <T> *temp;
            while (head != NULL)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        friend void show(Stack &s)
        {
            ValueNode <T> * h = s.head;
            while (h != NULL)
            {
                cout << h->val << " ";
                h = h->next;
            }
            cout << endl;
        }

};

bool is_op(char * token)
{
    bool op = false;

    if (strlen(token) == 1)
    {
        char ops[] = "+-x/^";
        op = strstr(ops, token) != NULL;
    }
    
    return op;
}

template <typename T>
double calc(T operand1, T operand2, char op[])
{
    double result;
    cout << operand1 << " " << operand2 << " " << op << endl;

    char c = op[0];
    cout << "Operator: " << c << endl;

    switch (c)
    {
        case '+': 
            result = operand1 + operand2;
            cout << "result: " << result << endl;
            break;  
        case '-':
            result = operand1 - operand2;
            cout << "result: " << result << endl;
            break;
        case 'x':
            result = operand1 * operand2;
            cout << "result: " << result << endl;
            break;
        case '/':
            result = operand1 / operand2;
            cout << "result: " << result << endl;
            break;
        case '^':
            result = pow(operand1, operand2);
            cout << "result: " << result << endl;
            break;
        default:
            result = 0.0;
            cout << "Invalid operator" << endl;
            break;
    }

    return result;
}

double solve_rpn(int count, char * tokens[])
{
    double result = 0.0;
    Stack <double> stack;

    for (int i = 1; i < count; i++)
    {
        if (!is_op(tokens[i]))
        {
            double number = atof(tokens[i]);
            stack.push(number);
        }
        else if (is_op(tokens[i]))
        {
            double operand1, operand2;
            stack.pop(operand2);
            stack.pop(operand1);
            double res = calc<double>(operand1, operand2, tokens[i]);
            stack.push(res);
        }
    }

    if (!stack.pop(result)) {
        cout << "Error: No result found!" << endl;
        return 0.0;
    }

    return result;
}


int main(int argc, char *argv[])
{
    cout << solve_rpn(argc, argv) << endl;

    return 0;
}
