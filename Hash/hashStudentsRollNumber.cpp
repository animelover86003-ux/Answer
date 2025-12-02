#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next; 
};

int TABLE_SIZE = 10; 

int hashFunction(int rollNo) {
    return rollNo % TABLE_SIZE;
}

void insert(Student* hashTable[], Student s) {
    int index = hashFunction(s.rollNo);
    Student* newNode = new Student;
    newNode->rollNo = s.rollNo;
    newNode->name = s.name;
    newNode->marks = s.marks;
    newNode->next = nullptr;

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void displayHashTable(Student* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Student* temp = hashTable[i];
        while (temp) {
            cout << "Roll No: " << temp->rollNo
                 << ", Name: " << temp->name
                 << ", Marks: " << temp->marks << endl;
            temp = temp->next;
        }
    }
}

Student* search(Student* hashTable[], int rollNo) {
    int index = hashFunction(rollNo);
    Student* temp = hashTable[index];
    while (temp) {
        if (temp->rollNo == rollNo) return temp;
        temp = temp->next;
    }
    return nullptr;
}
void freeHashTable(Student* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Student* temp = hashTable[i];
        while (temp) {
            Student* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
}

int main() {
    Student* hashTable[TABLE_SIZE] = {nullptr}; 
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> s.rollNo;
        cin.ignore();
        cout << "Name: ";
        getline(cin, s.name);
        cout << "Marks: ";
        cin >> s.marks;

        insert(hashTable, s);
    }

    cout << "\nStored Student Records:\n";
    displayHashTable(hashTable);

    int searchRoll;
    cout << "\nEnter roll number to search: ";
    cin >> searchRoll;
    Student* found = search(hashTable, searchRoll);
    if (found) {
        cout << "\nRecord Found:\n";
        cout << "Roll No: " << found->rollNo
             << ", Name: " << found->name
             << ", Marks: " << found->marks << endl;
    } else {
        cout << "\nRecord not found!\n";
    }

    freeHashTable(hashTable);
    return 0;
}
