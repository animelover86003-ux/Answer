#include <iostream>
using namespace std;
#define MAX 10
class MultipleQueues
{
private:
    int arr[MAX];
    int front1, rear1, front2, rear2;

public:
    MultipleQueues()
    {
        front1 = rear1 = -1;
        front2 = rear2 = MAX;
    }
    void enqueue1(int x)
    {
        if (rear1 + 1 == rear2)
        {
            cout << "Queue Overflow! Cannot insert in Queue1.\n";
            return;
        }
        if (front1 == -1)
            front1 = 0;
        arr[++rear1] = x;
        cout << "Inserted " << x << " in Queue1.\n";
    }
    void enqueue2(int x)
    {
        if (rear2 - 1 == rear1)
        {
            cout << "Queue Overflow! Cannot insert in Queue2.\n";
            return;
        }
        if (front2 == MAX)
            front2 = MAX - 1;
        arr[--rear2] = x;
        cout << "Inserted " << x << " in Queue2.\n";
    }
    void dequeue1()
    {
        if (front1 == -1 || front1 > rear1)
        {
            cout << "Queue1 Underflow!\n";
            return;
        }
        cout << "Removed " << arr[front1++] << " from Queue1.\n";
    }
    void dequeue2()
    {
        if (front2 == MAX || front2 < rear2)
        {
            cout << "Queue2 Underflow!\n";
            return;
        }
        cout << "Removed " << arr[front2--] << " from Queue2.\n";
    }
    void display1()
    {
        if (front1 == -1 || front1 > rear1)
        {
            cout << "Queue1 is empty.\n";
            return;
        }
        cout << "Queue1: ";
        for (int i = front1; i <= rear1; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void display2()
    {
        if (front2 == MAX || front2 < rear2)
        {
            cout << "Queue2 is empty.\n";
            return;
        }
        cout << "Queue2: ";
        for (int i = front2; i >= rear2; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    MultipleQueues mq;
    mq.enqueue1(10);
    mq.enqueue1(20);
    mq.enqueue2(100);
    mq.enqueue2(200);
    mq.display1();
    mq.display2();
    mq.dequeue1();
    mq.dequeue2();
    mq.display1();
    mq.display2();
    return 0;
}
