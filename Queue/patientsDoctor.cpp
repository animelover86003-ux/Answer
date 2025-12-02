#include <iostream>
using namespace std;
#define MAX 10
class ClinicQueue
{
private:
    string patients[MAX];
    int front, rear;

public:
    ClinicQueue()
    {
        front = rear = -1;
    }
    void checkIn(string name)
    {
        if (rear == MAX - 1)
        {
            cout << "Clinic Queue Full! Cannot add more patients.\n";
            return;
        }
        if (front == -1)
            front = 0;
        patients[++rear] = name;
        cout << name << " checked in.\n";
    }
    void assignDoctor()
    {
        if (front == -1 || front > rear)
        {
            cout << "No patients waiting.\n";
            return;
        }
        cout << patients[front] << " is assigned to doctor.\n";
        front++;
    }
    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "No patients in queue.\n";
            return;
        }
        cout << "Patients waiting: ";
        for (int i = front; i <= rear; i++)
        {
            cout << patients[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    ClinicQueue cq;
    cq.checkIn("John");
    cq.checkIn("Alice");
    cq.checkIn("Mark");
    cq.display();
    cq.assignDoctor();
    cq.display();
    cq.assignDoctor();
    cq.assignDoctor();
    cq.assignDoctor();
    return 0;
}
