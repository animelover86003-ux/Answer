#include <iostream>
using namespace std;

void printPass(int marks[], int n, int pass) {
    cout << "Pass " << pass << ": ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;
}

void bubbleSort(int marks[], int n) {
    cout << "\n--- Bubble Sort Pass by Pass ---\n";
    int pass = 1;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] < marks[j + 1]) {
                swap(marks[j], marks[j + 1]);
                swapped = true;
            }
        }
        printPass(marks, n, pass++);
        if (!swapped) break;
    }
}

void selectionSort(int marks[], int n) {
    cout << "\n--- Selection Sort Pass by Pass ---\n";
    int pass = 1;
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++)
            if (marks[j] > marks[maxIdx])
                maxIdx = j;

        if (maxIdx != i)
            swap(marks[i], marks[maxIdx]);

        printPass(marks, n, pass++);
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[n];
    cout << "Enter marks of students: ";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    int marksBubble[n], marksSelect[n];
    for (int i = 0; i < n; i++) {
        marksBubble[i] = marks[i];
        marksSelect[i] = marks[i];
    }

    bubbleSort(marksBubble, n);
    cout << "\nRoll numbers after Bubble Sort:\n";
    for (int i = 0; i < n; i++)
        cout << "Roll no. " << (i + 1) << " -> Marks " << marksBubble[i] << endl;

    selectionSort(marksSelect, n);
    cout << "\nRoll numbers after Selection Sort:\n";
    for (int i = 0; i < n; i++)
        cout << "Roll no. " << (i + 1) << " -> Marks " << marksSelect[i] << endl;

    return 0;
}
