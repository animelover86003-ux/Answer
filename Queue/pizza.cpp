#include <iostream>
using namespace std;
#define MAX 5
class PizzaParlour
{
private:
    int orders[MAX];
    int front, rear;

public:
    PizzaParlour()
    {
        front = rear = -1;
    }
    bool isFull()
    {
        return ((rear + 1) % MAX == front);
    }
    bool isEmpty()
    {
        return (front == -1);
    }
    void addOrder(int orderNo)
    {
        if (isFull())
        {
            cout << "Order limit reached! Cannot accept more orders.\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        orders[rear] = orderNo;
        cout << "Order " << orderNo << " placed successfully.\n";
    }
    void serveOrder()
    {
        if (isEmpty())
        {
            cout << "No orders to serve.\n";
            return;
        }
        cout << "Order " << orders[front] << " served.\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
    void displayOrders()
    {
        if (isEmpty())
        {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending Orders: ";
        int i = front;
        while (true)
        {
            cout << orders[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
int main()
{
    PizzaParlour pz;
    pz.addOrder(101);
    pz.addOrder(102);
    pz.addOrder(103);
    pz.addOrder(104);
    pz.addOrder(105);
    pz.displayOrders();
    pz.serveOrder();
    pz.serveOrder();
    pz.displayOrders();
    pz.addOrder(106);
    pz.displayOrders();
    return 0;
}
