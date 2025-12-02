#include <iostream>
using namespace std;

struct Node {
    char ch;
    Node* next;
};

Node* top = nullptr;

bool isEmpty() {
    return top == nullptr;
}

void push(char ch) {
    Node* newNode = new Node;
    newNode->ch = ch;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (isEmpty()) return '\0';
    Node* temp = top;
    char ch = top->ch;
    top = top->next;
    delete temp;
    return ch;
}

char peek() {
    if (isEmpty()) return '\0';
    return top->ch;
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBalanced(string expr) {
    top = nullptr; 
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch); 
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty() || !isMatchingPair(pop(), ch)) {
                return false; 
            }
        }
    }
    return isEmpty(); 
}

int main() {
    int choice;
    string expr;

    while (true) {
        cout << "\n--- Parentheses Checker Menu ---\n";
        cout << "1. Check Balanced Parentheses\n";
        cout << "2. Push Character onto Stack\n";
        cout << "3. Pop Character from Stack\n";
        cout << "4. Peek Top Character\n";
        cout << "5. Display Stack (Top to Bottom)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter parentheses string: ";
                cin >> expr;
                if (checkBalanced(expr))
                    cout << "Balanced Parentheses\n";
                else
                    cout << "Not Balanced Parentheses\n";
                break;

            case 2: {
                char ch;
                cout << "Enter character to push: ";
                cin >> ch;
                push(ch);
                cout << "Pushed " << ch << " onto stack\n";
                break;
            }

            case 3: {
                char ch = pop();
                if (ch == '\0')
                    cout << "Stack Underflow\n";
                else
                    cout << "Popped " << ch << " from stack\n";
                break;
            }

            case 4: {
                char ch = peek();
                if (ch == '\0')
                    cout << "Stack is empty\n";
                else
                    cout << "Top character: " << ch << endl;
                break;
            }

            case 5: {
                if (isEmpty()) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Stack elements (Top to Bottom): ";
                    Node* temp = top;
                    while (temp != nullptr) {
                        cout << temp->ch << " ";
                        temp = temp->next;
                    }
                    cout << endl;
                }
                break;
            }

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}
