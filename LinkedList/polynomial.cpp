#include <iostream>
using namespace std;
struct node
{
    int coeff;
    int exp;
    node *next;
};
class Polynomial
{
public:
    node *head;
    Polynomial() : head(nullptr) {}
    void insertnode(int c, int e)
    {
        node *newnode = new node{c, e, nullptr};
        if (!head || e > head->exp)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next && temp->next->exp > e)
                temp = temp->next;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
    static Polynomial add(Polynomial &p1, Polynomial &p2)
    {
        Polynomial result;
        node *t1 = p1.head;
        node *t2 = p2.head;
        while (t1 && t2)
        {
            if (t1->exp == t2->exp)
            {
                result.insertnode(t1->coeff + t2->coeff, t1->exp);
                t1 = t1->next;
                t2 = t2->next;
            }
            else if (t1->exp > t2->exp)
            {
                result.insertnode(t1->coeff, t1->exp);
                t1 = t1->next;
            }
            else
            {
                result.insertnode(t2->coeff, t2->exp);
                t2 = t2->next;
            }
        }
        while (t1)
        {
            result.insertnode(t1->coeff, t1->exp);
            t1 = t1->next;
        }
        while (t2)
        {
            result.insertnode(t2->coeff, t2->exp);
            t2 = t2->next;
        }
        return result;
    }
};
int main()
{
    Polynomial p1, p2, sum;
    int n, coeff, exp;
    cout << "Enter number of nodes for first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter coefficient and exponent: ";
        cin >> coeff >> exp;
        p1.insertnode(coeff, exp);
    }
    cout << "Enter number of nodes for second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter coefficient and exponent: ";
        cin >> coeff >> exp;
        p2.insertnode(coeff, exp);
    }
    cout << "\nFirst Polynomial: ";
    p1.display();
    cout << "Second Polynomial: ";
    p2.display();
    sum = Polynomial::add(p1, p2);
    cout << "Sum of Polynomials: ";
    sum.display();
    return 0;
}