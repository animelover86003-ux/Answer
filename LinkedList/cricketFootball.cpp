#include <iostream>
#include <string.h>
using namespace std;

struct node {
    char name[20];
    bool cricket;
    bool football;
    node* next;
};

class nodeList {
    node* head;

public:
    nodeList() { head = NULL; }

    int menu() {
        int ch;
        cout << "\n--- node Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Students who like BOTH Cricket & Football\n";
        cout << "3. Students who like ONLY one sport (Cricket / Football)\n";
        cout << "4. Students who like NEITHER Cricket nor Football\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        return ch;
    }

    node* createNode() {
        node* s = new node;
        cout << "Enter Name: ";
        cin >> s->name;

        int x;
        cout << "Like Cricket? (1-Yes, 0-No): ";
        cin >> x;
        s->cricket = (x == 1);

        cout << "Like Football? (1-Yes, 0-No): ";
        cin >> x;
        s->football = (x == 1);

        s->next = NULL;
        return s;
    }

    void addStudent() {
        char again;
        do {
            node* n = createNode();

            if (head == NULL)
                head = n;
            else {
                node* t = head;
                while (t->next != NULL)
                    t = t->next;
                t->next = n;
            }

            cout << "Add more? (y/n): ";
            cin >> again;
        } while (again == 'y' || again == 'Y');
    }

    void showBoth() {
        cout << "\nStudents who like BOTH Cricket & Football:\n";
        node* t = head;
        while (t != NULL) {
            if (t->cricket && t->football)
                cout << t->name << "\n";
            t = t->next;
        }
    }

    void showOnlyOne() {
        cout << "\nStudents who like ONLY ONE sport:\n";
        node* t = head;
        while (t != NULL) {
            if ((t->cricket && !t->football) || (!t->cricket && t->football))
                cout << t->name << "\n";
            t = t->next;
        }
    }

    void showNeither() {
        cout << "\nStudents who like NEITHER sport:\n";
        int cnt = 0;
        node* t = head;

        while (t != NULL) {
            if (!t->cricket && !t->football) {
                cout << t->name << "\n";
                cnt++;
            }
            t = t->next;
        }
        cout << "Total count: " << cnt << "\n";
    }
};

int main() {
    nodeList s;
    while (true) {
        int ch = s.menu();
        if (ch == 1) s.addStudent();
        else if (ch == 2) s.showBoth();
        else if (ch == 3) s.showOnlyOne();
        else if (ch == 4) s.showNeither();
        else if (ch == 5) break;
        else cout << "Invalid choice!\n";
    }
    return 0;
}
