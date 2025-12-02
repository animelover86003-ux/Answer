#include<iostream>
using namespace std;

int main() {

    int matrix[10][10], sparse[100][3], fast[100][3];
    int k = 1, rows, cols;

    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    cout << "Enter elements: ";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    sparse[0][0] = rows;
    sparse[0][1] = cols;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }

    sparse[0][2] = k - 1;

    cout << "Sparse:\n";
    for (int i = 0; i < k; i++)
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;

    int total[100] = {0}, index[100];

    for (int i = 1; i <= sparse[0][2]; i++)
        total[sparse[i][1]]++;

    index[0] = 1;
    for (int i = 1; i < cols; i++)
        index[i] = index[i - 1] + total[i - 1];

    for (int i = 1; i <= sparse[0][2]; i++) {
        int col = sparse[i][1];
        int pos = index[col];

        fast[pos][0] = sparse[i][1];
        fast[pos][1] = sparse[i][0];
        fast[pos][2] = sparse[i][2];

        index[col]++;
    }

    fast[0][0] = cols;
    fast[0][1] = rows;
    fast[0][2] = sparse[0][2];

    cout << "Fast Transpose:\n";
    for (int i = 0; i <= sparse[0][2]; i++)
        cout << fast[i][0] << " " << fast[i][1] << " " << fast[i][2] << endl;

    return 0;
}
