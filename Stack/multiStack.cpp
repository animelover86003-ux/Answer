#include <iostream>
using namespace std;
class MultiStack
{
private:
    int *arr;
    int *top;
    int size, stacks;

public:
    MultiStack(int n, int k)
    {
        size = n;
        stacks = k;
        arr = new int[size];
        top = new int[stacks];
        for (int i = 0; i < stacks; i++)
        {
            top[i] = (i * (size / stacks)) - 1; 
        }
    }
    void push(int stackNo, int value)
    {
        int start = stackNo * (size / stacks);
        int end = (stackNo + 1) * (size / stacks) - 1;
        if (top[stackNo] == end)
        {
            cout << "Stack " << stackNo << " Overflow!" << endl;
            return;
        }
        top[stackNo]++;
        arr[top[stackNo]] = value;
        cout << "Pushed " << value << " into Stack " << stackNo << endl;
    }
    void pop(int stackNo)
    {
        int start = stackNo * (size / stacks);
        if (top[stackNo] < start)
        {
            cout << "Stack " << stackNo << " Underflow!" << endl;
            return;
        }
        cout << "Popped " << arr[top[stackNo]] << " from Stack " << stackNo << endl;
        top[stackNo]--;
    }
    void display(int stackNo)
    {
        int start = stackNo * (size / stacks);
        if (top[stackNo] < start)
        {
            cout << "Stack " << stackNo << " is Empty!" << endl;
            return;
        }
        cout << "Stack " << stackNo << ": ";
        for (int i = start; i <= top[stackNo]; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    MultiStack ms(12, 3); 
    ms.push(0, 10);
    ms.push(0, 20);
    ms.push(1, 30);
    ms.push(1, 40);
    ms.push(2, 50);
    ms.display(0);
    ms.display(1);
    ms.display(2);
    ms.pop(0);
    ms.display(0);
    ms.pop(2);
    ms.display(2);
    return 0;
}
