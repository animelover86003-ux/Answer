#include <iostream>
using namespace std;

struct Employee {
    string name;
    float height;
    float weight;
    float avg;
};

// Print array for pass-by-pass analysis
void printPass(Employee arr[], int n, int pass) {
    cout << "Pass " << pass << ":\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].name << "(" << arr[i].avg << ")  ";
    cout << endl;
}

// Merge function
void merge(Employee arr[], int l, int m, int r, int &pass) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Employee L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    printPass(arr, r - l + 1, pass++);
}

// Merge Sort function
void mergeSort(Employee arr[], int l, int r, int &pass) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, pass);
        mergeSort(arr, m + 1, r, pass);
        merge(arr, l, m, r, pass);
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name, height and weight of employee " << i + 1 << ": ";
        cin >> arr[i].name >> arr[i].height >> arr[i].weight;
        arr[i].avg = (arr[i].height + arr[i].weight) / 2.0;
    }

    int pass = 1;
    mergeSort(arr, 0, n - 1, pass);

    cout << "\nEmployees sorted by average (ascending):\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].name << " - Avg: " << arr[i].avg << endl;

    cout << "\nTime Complexity Analysis:\n";
    cout << "Merge Sort: Best, Average, Worst = O(n log n)\n";
    cout << "Conclusion: Merge Sort is efficient and generally faster than Bubble or Selection Sort for large lists.\n";

    return 0;
}
