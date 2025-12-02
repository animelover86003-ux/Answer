#include <iostream>
using namespace std;

struct Node {
    int sh, sm;   
    int eh, em;   
    Node* next;
};

class Scheduler {
    Node* head;

public:
    Scheduler() { head = NULL; }

    void display() {
        if (!head) {
            cout << "No appointments scheduled.\n";
            return;
        }
        Node* temp = head;
        cout << "Appointments:\n";
        while (temp) {
            cout << temp->sh << ":" << (temp->sm < 10 ? "0" : "") << temp->sm
                 << " - "
                 << temp->eh << ":" << (temp->em < 10 ? "0" : "") << temp->em
                 << "\n";
            temp = temp->next;
        }
    }

    bool checkConflict(int sh, int sm, int eh, int em) {
        Node* temp = head;

        int startB = sh * 60 + sm;
        int endB   = eh * 60 + em;

        while (temp) {
            int startA = temp->sh * 60 + temp->sm;
            int endA   = temp->eh * 60 + temp->em;

            if (!(endB <= startA || startB >= endA))
                return true;

            temp = temp->next;
        }
        return false;
    }

    void bookAppointment(int sh, int sm, int duration) {

        int eh = sh + (sm + duration) / 60;
        int em = (sm + duration) % 60;

        if (checkConflict(sh, sm, eh, em)) {
            cout << "Conflict detected! Cannot book.\n";
            return;
        }

        Node* n = new Node{sh, sm, eh, em, NULL};

        int startNew = sh * 60 + sm;

        if (!head) {
            head = n;
            cout << "Appointment booked.\n";
            return;
        }

        int startHead = head->sh * 60 + head->sm;

        if (startNew < startHead) {
            n->next = head;
            head = n;
            cout << "Appointment booked.\n";
            return;
        }

        Node* temp = head;

        while (temp->next) {
            int nextStart = temp->next->sh * 60 + temp->next->sm;
            if (nextStart >= startNew) break;
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;

        cout << "Appointment booked.\n";
    }

    void cancelAppointment(int sh, int sm) {
        if (!head) {
            cout << "No appointments to cancel.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp) {
            if (temp->sh == sh && temp->sm == sm) {

                if (!prev)
                    head = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "Appointment cancelled.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "No matching appointment found.\n";
    }
};

int main() {
    Scheduler s;
    int choice, sh, sm, dur;

    do {
        cout << "\n1. Display Appointments\n2. Book Appointment\n3. Cancel Appointment\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.display();
            break;

        case 2:
            cout << "Enter start hour & minute: ";
            cin >> sh >> sm;
            cout << "Enter duration (minutes): ";
            cin >> dur;
            s.bookAppointment(sh, sm, dur);
            break;

        case 3:
            cout << "Enter start hour & minute to cancel: ";
            cin >> sh >> sm;
            s.cancelAppointment(sh, sm);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
