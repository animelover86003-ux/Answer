#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList() : head(nullptr) {}
    void insertBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head)
        {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
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
    void insertAtPosition(int value, int pos)
    {
        if (pos == 1)
        {
            insertBeginning(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next;
        if (!temp)
        {
            cout << "Position out of bounds\n";
            return;
        }
        newNode->next = temp->next;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void deleteBeginning()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete temp;
    }
    void deleteEnd()
    {
        if (!head)
            return;
        Node *temp = head;
        if (!temp->next)
        { // Only one node
            delete head;
            head = nullptr;
            return;
        }
        while (temp->next)
            temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }
    void deleteAtPosition(int pos)
    {
        if (!head)
            return;
        if (pos == 1)
        {
            deleteBeginning();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos && temp; i++)
            temp = temp->next;
        if (!temp)
        {
            cout << "Position out of bounds\n";
            return;
        }
        temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
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
};
int main()
{
    DoublyLinkedList dll;
    int choice, value, pos;
    do
    {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete at Position\n";
        cout << "7. Display\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dll.insertBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            dll.insertEnd(value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            dll.insertAtPosition(value, pos);
            break;
        case 4:
            dll.deleteBeginning();
            break;
        case 5:
            dll.deleteEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            dll.deleteAtPosition(pos);
            break;
        case 7:
            cout << "Doubly Linked List: ";
            dll.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
