#include<iostream>
using namespace std;

int main(){
    int matrix[10][10],sparse[100][3],k =1,rows,cols;

    cout << "Enter number of rows and cols:" ;
    cin >> rows;
    cin >> cols;

    cout << "Enter Elements : ";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)   
            cin >> matrix[i][j];
        
    sparse[0][0] = rows;
    sparse[0][1] = cols;

    for(int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if(matrix[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }

    sparse[0][2]= k-1;
    
    cout << "Sparse Matrix Representation : \n";

    for(int i =0;i < k ;i++)
            cout << sparse[i][0] << " " << sparse[i][1]  << " "<< sparse[i][2] << endl;

    cout << "Transpose :";

    for(int i = 0 ; i < cols ; i++)
        for (int  j = 1; j < k; j++)
            if(sparse[j][1] == i){
                cout << sparse[j][1] << " " << sparse[j][0] << " " << sparse [j][2] << endl ; 
            }
        
    return 0;
}