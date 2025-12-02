#include <iostream>
using namespace std;
class Node
{
public:
    int callID;
    Node *next;
    Node(int id)
    {
        callID = id;
        next = NULL;
    }
};
class CallCenterQueue
{
private:
    Node *front;
    Node *rear;

public:
    CallCenterQueue()
    {
        front = rear = NULL;
    }
    void enqueue(int id)
    {
        Node *temp = new Node(id);
        if (rear == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        cout << "New call " << id << " added to queue.\n";
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "No calls waiting. Agents are free.\n";
            return;
        }
        cout << "Call " << front->callID << " is being attended.\n";
        Node *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
    void display()
    {
        if (front == NULL)
        {
            cout << "No calls in the queue.\n";
            return;
        }
        cout << "Calls waiting in queue: ";
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->callID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    CallCenterQueue cc;
    cc.enqueue(101);
    cc.enqueue(102);
    cc.enqueue(103);
    cc.display();
    cc.dequeue();
    cc.display();
    cc.enqueue(104);
    cc.enqueue(105);
    cc.display();
    cc.dequeue();
    cc.dequeue();
    cc.display();
    return 0;
}
