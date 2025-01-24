/*Write a function that takes a 3X3 matrix as input and returns a matrix having lower triangular matrix and upper triangular matrix.

Input Format: Three consecutive lines, each containing three space-separated integers. Each line represents a row of a 3x3 matrix.
Output Format: Output the lower triangular matrix and upper triangular matrix in 3 lines keeping 6 integers in a single line.

Sample Input:
6 5 4
1 2 5
7 9 7

Sample Output:
6 0 0 6 5 4
1 2 0 0 2 5
7 9 7 0 0 7*/

#include <iostream>
#include <vector>

using namespace std;

class matrixClass{
public:
    int n,m;
    vector<vector<int>> M;
    matrixClass(int shape0, int shape1, vector<vector<int>> matrix){
        n = shape0;
        m = shape1;
        M = matrix;
    }
    
    void displayMatrix(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }

    void matrixConverter(){
        for(int i=0; i<3; i++){
            // Print lower triangular part
            for(int j=0; j<3; j++){
                if(i >= j) cout << M[i][j] << " ";
                else cout << 0 << " ";
            }
            // Print upper triangular part
            for(int j=0; j<3; j++){
                if(i <= j) cout << M[i][j] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }

};


int main()
{
    vector<vector<int>> matrix(3, vector<int>(3,0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>matrix[i][j];
        }
    }

    matrixClass M(3,3, matrix);
    M.matrixConverter();
    return 0;
}