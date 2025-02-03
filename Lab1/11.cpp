/*Write a program that takes an integer n and an nxn matrix as input, and outputs the lower triangular matrix of the given matrix.

Note: A lower triangular matrix is a matrix where all the elements including the main diagonal are zero.

Input format
1. The first line of input contains an integer n, representing the size of the matrix.
2. The next n lines contain n integers each, representing the elements of the matrix

Output format
Print the lower triangular matrix.

Example Input
3
1 2 3
4 5 6
7 8 9


Output
0 0 0
4 0 0
7 8 0*/

#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> matrix;

public:
    // Constructor to initialize the matrix size
    SquareMatrix(int size) : n(size) {
        matrix.resize(n, vector<int>(n));
    }

    // Method to input matrix elements
    void inputMatrix() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
    }

    // Method to print the lower triangular matrix
    void printLowerTriangularMatrix() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i <= j) {
                    cout << 0;
                } else {
                    cout << matrix[i][j];
                }
                //if (j < n - 1) {
                    cout << " ";
            //    }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    SquareMatrix sm(n);
    sm.inputMatrix();
    sm.printLowerTriangularMatrix();

    return 0;
}