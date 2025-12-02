#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList() : head(nullptr) {}
    void insertEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void bubbleSort()
    {
        if (!head)
            return;
        bool swapped;
        Node *ptr;
        Node *last = nullptr;
        do
        {
            swapped = false;
            ptr = head;
            while (ptr->next != last)
            {
                if (ptr->data > ptr->next->data)
                {
                    // Swap data
                    int temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            last = ptr; // Last node is sorted
        } while (swapped);
    }
};
int main()
{
    DoublyLinkedList dll;
    int n, value;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        dll.insertEnd(value);
    }
    cout << "\nDoubly Linked List before sorting: ";
    dll.display();
    dll.bubbleSort();
    cout << "Doubly Linked List after Bubble Sort: ";
    dll.display();
    return 0;
}