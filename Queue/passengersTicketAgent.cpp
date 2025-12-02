#include <iostream>
using namespace std;
#define MAX 5
class PassengerQueue
{
private:
    int queue[MAX];
    int front, rear;

public:
    PassengerQueue()
    {
        front = rear = -1;
    }
    bool isFull()
    {
        return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
    }
    bool isEmpty()
    {
        return (front == -1);
    }
    void insertFront(int x)
    {
        if (isFull())
        {
            cout << "Queue is full! Cannot add passenger.\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front = front - 1;
        }
        queue[front] = x;
        cout << "Passenger " << x << " added at front.\n";
    }
    void insertRear(int x)
    {
        if (isFull())
        {
            cout << "Queue is full! Cannot add passenger.\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        queue[rear] = x;
        cout << "Passenger " << x << " added at rear.\n";
    }
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! No passenger to remove.\n";
            return;
        }
        cout << "Passenger " << queue[front] << " removed from front.\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! No passenger to remove.\n";
            return;
        }
        cout << "Passenger " << queue[rear] << " removed from rear.\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear = rear - 1;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Passengers in Queue: ";
        int i = front;
        while (true)
        {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
int main()
{
    PassengerQueue pq;
    pq.insertRear(101);
    pq.insertRear(102);
    pq.insertFront(100);
    pq.display();
    pq.deleteFront();
    pq.display();
    pq.insertRear(103);
    pq.insertRear(104);
    pq.insertFront(99);
    pq.display();
    pq.deleteRear();
    pq.display();
    return 0;
}
