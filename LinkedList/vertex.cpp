#include <iostream>
using namespace std;
#include <algorithm>

typedef struct club
{
    char name[20];
    int prn;
    struct club *next;
} *node;

int getChoice()
{
    int num1;
    cout << "\nVertex Club Membership record\n";
    cout << "Enter 1 For Adding member\n";
    cout << "Enter 2 For Display member Info\n";
    cout << "Enter 3 For Couting Member\n";
    cout << "Enter 4 For Addition of Member\n";
    cout << "Enter 5 To Delete the member\n";
    cout << "Enter 6 To Serach the member by prn\n";
    cout << "Enter 7 To Sort The Member by prn\n";
    cout << "Enter The Correct Choice: ";
    cin >> num1;
    return num1;
}

node accept()
{
    node a = new struct club;
    cout << "Enter Name: ";
    cin >> a->name;
    cout << "Enter Prn: ";
    cin >> a->prn;
    a->next = NULL;

    return a;
}

void display(node first)
{
    node a = first;
    if (a == first)
    {
        cout << a->name << "\t" << "President" << "\n";
        a = a->next;
    }
    while (a != NULL)
    {
        cout << a->name << "\t" << "Member" << "\n";
        a = a->next;
        if (a->next == NULL)
        {
            cout << a->name << "\t" << "Secreatory" << "\n";
            a = a->next;
        }
    }
}

void addition(node first, int count)
{
    int loc;
    node a = first;
    cout << "Enter Location : ";
    cin >> loc;
    if (loc == 1 && loc == count)
    {
        cout << "You Can't Take Position of President & Secreatory";
    }
    else
    {
        node temp = accept();
        int i = 1;
        while (i < loc - 1)
        {
            a = a->next;
            i++;
        }
        temp->next = a->next;
        a->next = temp;
    }
}

void deletion(node first, int count)
{
    int loc;
    node a = first;
    cout << "Enter Location : ";
    cin >> loc;
    if (loc == 1 && loc == count)
    {
        cout << "You Can't Delete Position of President & Secreatory";
    }
    else
    {
        node temp;
        int i = 1;
        while (i != loc)
        {
            temp = a;
            a = a->next;
            i++;
        }
        temp->next = a->next;
    }
}

void search(node first, int count)
{
    int num, code = 0;
    node a = first;
    cout << "Enter Prn To search : ";
    cin >> num;
    while (a->next != NULL)
    {
        if (a->prn == num)
        {
            code = 2;
            break;
        }
        a = a->next;
    }
    if (a->next == NULL)
    {
        cout << "Item Not Found\n";
    }
    else
    {
        cout << "Item Found\n";

        cout << a->name << "\t" << a->prn << "\n";
    }
}

void sort(node first, int count)
{
    node a = first;
    node temp;

    int i=0;
    while (i<4)
    {
        temp = a;
        a = a->next;
        if (a->prn<temp->prn)
        {
            // temp->name=temp->name;
            temp->prn=temp->prn;
            temp->prn=a->prn;
            a->prn=temp->prn;

        }
        i++;
    }
}

void swap()
{
    
}
int main()
{
    node first = NULL;

    int code = 0;
    int count = 1;

    while (true)
    {
        int choice = getChoice();
        switch (choice)
        {
        case 1:
        {
            char ch;
            do
            {
                node newnode = accept();
                if (first == NULL)
                {
                    first = newnode;
                }
                else
                {
                    node a = first;
                    while (a->next != NULL)
                    {
                        a = a->next;
                    }
                    a->next = newnode;
                }
                cout << "Add another club Member? (y/n): ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    count++;
                }

            } while (ch == 'y' || ch == 'Y');
            break;
        }

        case 2:
            cout << "" << endl;
            display(first);
            break;

        case 3:
            cout << "Total Members :" << count << "(Including President And Secretary) \n";
            break;

        case 4:
            cout << "Addition of member\n";
            addition(first, count);
            break;

        case 5:
            cout << "Deletion \n";
            deletion(first, count);
            break;

        case 6:
            cout << "Search \n";
            search(first, count);
            break;

        case 7:
            cout << "Sort \n";
            sort(first, count);
            break;
        default:
            cout << "Invalid Choice\n\n";
        }
    }
    cout << "\n--> The Program is Exited\n\n";
}