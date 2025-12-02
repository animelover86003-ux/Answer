#include <iostream>
using namespace std;

void generateOdd(int n, int sq[][50]) {
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        sq[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (sq[newi][newj] != 0) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }
}

void generateDoublyEven(int n, int sq[][50]) {
    int num = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sq[i][j] = num++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i % 4 == j % 4) || ((i + j) % 4 == 3))
                sq[i][j] = (n * n + 1) - sq[i][j];
}

void generateSinglyEven(int n, int sq[][50]) {
    int half = n / 2;
    int k = half * half;

    int temp[50][50] = {0};
    generateOdd(half, temp);

    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++) {
            sq[i][j] = temp[i][j];
            sq[i + half][j] = temp[i][j] + 2 * k;
            sq[i][j + half] = temp[i][j] + 3 * k;
            sq[i + half][j + half] = temp[i][j] + k;
        }

    int cols = (n - 2) / 4;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < cols; j++)
            if (i < half) {
                int tempv = sq[i][j];
                sq[i][j] = sq[i + half][j];
                sq[i + half][j] = tempv;
            }

    for (int i = 0; i < half; i++) {
        int j = cols;
        int tempv = sq[i][j];
        sq[i][j] = sq[i + half][j];
        sq[i + half][j] = tempv;
    }
}

bool checkMagic(int n, int sq[][50]) {
    int target = 0;

    for (int j = 0; j < n; j++)
        target += sq[0][j];

    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += sq[i][j];

        if (sum != target) return false;
    }

    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += sq[i][j];

        if (sum != target) return false;
    }

    int d1 = 0;
    for (int i = 0; i < n; i++)
        d1 += sq[i][i];

    if (d1 != target) return false;

    int d2 = 0;
    for (int i = 0; i < n; i++)
        d2 += sq[i][n - i - 1];

    if (d2 != target) return false;

    return true;
}

int main() {
    int n;
    cout << "Enter order of magic square (n < 50): ";
    cin >> n;

    int sq[50][50] = {0};

    if (n % 2 == 1) {
        generateOdd(n, sq);
    } else if (n % 4 == 0) {
        generateDoublyEven(n, sq);
    } else {
        generateSinglyEven(n, sq);
    }

    cout << "\nMagic Square:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << sq[i][j] << "\t";
        cout << endl;
    }

    if (checkMagic(n, sq))
        cout << "\nThis is a VALID Magic Square.\n";
    else
        cout << "\nThis is NOT a Magic Square.\n";

    return 0;
}
