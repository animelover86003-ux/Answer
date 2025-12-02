#include <iostream>
#include <cctype>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

bool isEmpty() {
    return top == nullptr;
}

void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed " << value << " onto stack\n";
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return 0;
    }
    Node* temp = top;
    int value = top->data;
    top = top->next;
    delete temp;
    cout << "Popped " << value << " from stack\n";
    return value;
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return 0;
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements (Top to Bottom): ";
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int evaluatePostfix(string expr) {
    top = nullptr; 
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (ch) {
                case '+': push(op2 + op1); break;
                case '-': push(op2 - op1); break;
                case '*': push(op2 * op1); break;
                case '/': push(op2 / op1); break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return 0;
            }
        }
    }
    return pop();
}

int main() {
    int choice, value;
    string expr;

    while (true) {
        cout << "\n--- Postfix Evaluation Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display Stack\n";
        cout << "5. Evaluate Postfix Expression\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if (!isEmpty())
                    cout << "Top element: " << value << endl;
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Enter postfix expression: ";
                cin >> expr;
                value = evaluatePostfix(expr);
                cout << "Result = " << value << endl;
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
