#include <iostream>
#include <cstring>
using namespace std;

char stackArr[50];
int top = -1;

void push(char x)
{
    stackArr[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    return stackArr[top--];
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main()
{
    char infix[50], postfix[50];
    cout << "Enter Infix Expression : ";
    cin >> infix;

    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {

        char c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (stackArr[top] != '(')
                postfix[j++] = pop();
            pop(); 
        }
        else if (isOperator(c))
        {
            while (top != -1 && precedence(stackArr[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    cout << "Postfix Expression : " << postfix;
    return 0;
}
