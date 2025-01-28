/*Given a matrix M (r x c) as input and write a complete the function which outputs an array which contains the column wise sum of of the transpose of M. 
(Do not use any library other than iostream)

Input format:
First line contains two integers r and c,      the rows and the columns of the matrix respectively.
Next r lines contains c integers each,         representing the elements of the row.

Constraints: 1 <= r,c <= 100  |  -1000 <= matrix elements <= 1000

Output format:
There should be single line output with space separated integers:     the sums of each column of the transpose of the matrix

Sample Test Case:
Input:
2 3 
1 2 3 
4 5 6 
Output:
6 15

Explanation:
Transpose of the matrix is:
1 4
2 5
3 6
Sum of Cols is: 1+2+3 = 6, 4+5+6 = 15*/
#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> matrix;

public:
    // Constructor to initialize the matrix size
    SquareMatrix(int size) : n(size), matrix(size, vector<int>(size, 0)) {
        // Matrix initialized with zeros
    }

    // Method to input matrix elements
    void inputMatrix() {
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> matrix[i][j];
            }
        }
    }

    // Method to print the lower triangular matrix
    void printLowerTriangularMatrix() const {
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(j > i){
                    cout << "0 ";
                }
                else{
                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    // Create a SquareMatrix object
    SquareMatrix sm(n);

    // Input matrix elements
    sm.inputMatrix();

    // Print the lower triangular matrix
    sm.printLowerTriangularMatrix();

    return 0;
}