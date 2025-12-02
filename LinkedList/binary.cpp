#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class BinaryNumber {
public:
    Node *head;
    Node *tail;

    BinaryNumber() {
        head = nullptr;
        tail = nullptr;
    }

    void insertBit(int bit) {
        Node *newNode = new Node(bit);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    void onesComplement() {
        Node *temp = head;
        while (temp != nullptr) {
            temp->data = 1 - temp->data;
            temp = temp->next;
        }
    }

    void twosComplement() {
        onesComplement();

        Node *temp = tail;
        int carry = 1;

        while (temp != nullptr && carry) {
            int sum = temp->data + carry;
            temp->data = sum % 2;
            carry = sum / 2;
            temp = temp->prev;
        }

        if (carry == 1) {
            Node *newNode = new Node(1);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    static BinaryNumber add(BinaryNumber &a, BinaryNumber &b) {
        BinaryNumber result;

        Node *t1 = a.tail;
        Node *t2 = b.tail;
        int carry = 0;

        while (t1 != nullptr || t2 != nullptr || carry != 0) {
            int sum = carry;

            if (t1 != nullptr) {
                sum += t1->data;
                t1 = t1->prev;
            }

            if (t2 != nullptr) {
                sum += t2->data;
                t2 = t2->prev;
            }

            Node *newNode = new Node(sum % 2);
            newNode->next = result.head;

            if (result.head != nullptr)
                result.head->prev = newNode;

            result.head = newNode;

            if (result.tail == nullptr)
                result.tail = newNode;

            carry = sum / 2;
        }

        return result;
    }
};

int main() {
    BinaryNumber bin1, bin2;
    string s1, s2;

    cout << "Enter first binary number: ";
    cin >> s1;
    for (char c : s1) bin1.insertBit(c - '0');

    cout << "Enter second binary number: ";
    cin >> s2;
    for (char c : s2) bin2.insertBit(c - '0');

    cout << "\nBinary Numbers Entered:\n";
    bin1.display();
    bin2.display();

    bin1.onesComplement();
    cout << "\n1's Complement of first number: ";
    bin1.display();

    bin1.twosComplement();
    cout << "2's Complement of first number: ";
    bin1.display();

    BinaryNumber sum = BinaryNumber::add(bin1, bin2);
    cout << "\nSum of both binary numbers: ";
    sum.display();

    return 0;
}
