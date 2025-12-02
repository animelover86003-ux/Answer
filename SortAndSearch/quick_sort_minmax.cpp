#include <iostream>
using namespace std;


void printPass(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partitionQS(int arr[], int low, int high, int n, int pass) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }

    int t = arr[i+1]; arr[i+1] = arr[high]; arr[high] = t;

    cout << "Pass " << pass << ": ";
    printPass(arr, n);

    return i + 1;
}

void quickSort(int arr[], int low, int high, int n, int &pass) {
    if (low < high) {
        int pi = partitionQS(arr, low, high, n, pass);
        pass++;
        quickSort(arr, low, pi - 1, n, pass);
        quickSort(arr, pi + 1, high, n, pass);
    }
}


void minMax(int arr[], int low, int high, int &mn, int &mx) {
    if (low == high) {
        if (arr[low] < mn) mn = arr[low];
        if (arr[low] > mx) mx = arr[low];
        return;
    }

    if (high - low == 1) {
        if (arr[low] < arr[high]) {
            if (arr[low] < mn) mn = arr[low];
            if (arr[high] > mx) mx = arr[high];
        } else {
            if (arr[high] < mn) mn = arr[high];
            if (arr[low] > mx) mx = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;

    minMax(arr, low, mid, mn, mx);
    minMax(arr, mid + 1, high, mn, mx);
}


int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int arr[n];
    cout << "Enter marks: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n--- QUICK SORT PASS BY PASS ---\n";
    int pass = 1;
    quickSort(arr, 0, n - 1, n, pass);

    cout << "\nSorted Marks: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    int mn = 999999, mx = -999999;
    minMax(arr, 0, n - 1, mn, mx);

    cout << "\n\nMinimum Marks = " << mn;
    cout << "\nMaximum Marks = " << mx;
    return 0;
}
