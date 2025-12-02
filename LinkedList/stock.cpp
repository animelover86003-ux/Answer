#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class StockPriceTracker
{
private:
    Node *top;

public:
    StockPriceTracker()
    {
        top = NULL;
    }
    // record(price) -> push
    void record(int price)
    {
        Node *newNode = new Node();
        newNode->data = price;
        newNode->next = top;
        top = newNode;
        cout << "Recorded price: " << price << endl;
    }
    // remove() -> pop
    int remove()
    {
        if (isEmpty())
        {
            cout << "No prices to remove (Stack Underflow)." << endl;
            return -1;
        }
        int removed = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return removed;
    }
    // latest() -> peek
    int latest()
    {
        if (isEmpty())
        {
            cout << "No prices recorded." << endl;
            return -1;
        }
        return top->data;
    }
    // isEmpty()
    bool isEmpty()
    {
        return (top == NULL);
    }
    // Display stack (optional)
    void display()
    {
        if (isEmpty())
        {
            cout << "No prices recorded." << endl;
            return;
        }
        cout << "Price History: ";
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    StockPriceTracker tracker;
    tracker.record(100);
    tracker.record(105);
    tracker.record(110);
    tracker.display();
    cout << "Latest price: " << tracker.latest() << endl;
    cout << "Removed price: " << tracker.remove() << endl;
    tracker.display();
    return 0;
}
