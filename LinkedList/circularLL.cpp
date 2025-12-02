#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int seatNo;
    int status; 
    Node* next;
    Node* prev;
};

const int ROWS = 8;
const int SEATS = 8;

Node* rows[ROWS];

void initialize() {
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        Node* head = NULL;
        Node* last = NULL;

        for (int j = 1; j <= SEATS; j++) {
            Node* n = new Node;
            n->seatNo = j;
            n->status = rand() % 2;
            n->next = n->prev = NULL;

            if (!head) {
                head = n;
                last = n;
            } else {
                last->next = n;
                n->prev = last;
                last = n;
            }
        }

        head->prev = last;
        last->next = head;

        rows[i] = head;
    }
}

void displaySeats() {
    cout << "\nAvailable Seats:\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Row " << i + 1 << ": ";
        Node* temp = rows[i];
        bool printed = false;

        if (temp) {
            Node* start = temp;
            do {
                if (temp->status == 0) {
                    cout << temp->seatNo << " ";
                    printed = true;
                }
                temp = temp->next;
            } while (temp != start);
        }

        if (!printed) cout << "No seats available";
        cout << endl;
    }
}

void bookSeats() {
    int r, s;
    char more;

    do {
        cout << "Enter row (1-8): ";
        cin >> r;
        cout << "Enter seat (1-8): ";
        cin >> s;

        if (r < 1 || r > ROWS || s < 1 || s > SEATS) {
            cout << "Invalid input!\n";
        } else {
            Node* temp = rows[r - 1];
            Node* start = temp;

            do {
                if (temp->seatNo == s) break;
                temp = temp->next;
            } while (temp != start);

            if (temp->status == 1)
                cout << "Already booked!\n";
            else {
                temp->status = 1;
                cout << "Seat booked.\n";
            }
        }

        cout << "Book more? (y/n): ";
        cin >> more;

    } while (more == 'y' || more == 'Y');
}

void cancelBooking() {
    int r, s;
    char more;

    do {
        cout << "Enter row (1-8): ";
        cin >> r;
        cout << "Enter seat (1-8): ";
        cin >> s;

        if (r < 1 || r > ROWS || s < 1 || s > SEATS) {
            cout << "Invalid input!\n";
        } else {
            Node* temp = rows[r - 1];
            Node* start = temp;

            do {
                if (temp->seatNo == s) break;
                temp = temp->next;
            } while (temp != start);

            if (temp->status == 0)
                cout << "Not Booked Anyway!\n";
            else {
                temp->status = 0;
                cout << "Booking cancelled.\n";
            }
        }

        cout << "Cancel more? (y/n): ";
        cin >> more;

    } while (more == 'y' || more == 'Y');
}

int main() {
    initialize();
    int choice;

    do {
        cout << "\n--- Galaxy Multiplex Ticket Reservation ---\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seat(s)\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displaySeats(); break;
            case 2: bookSeats(); break;
            case 3: cancelBooking(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
