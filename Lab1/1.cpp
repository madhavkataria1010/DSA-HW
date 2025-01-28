/*You are given a matrix of size n x n, which is to be the argument for the function along with the matrix. You are expected to print the sum of the left diagonal and right diagonal of the matrix.

Input:
1. The first line contain an integer n greater than 1 and less than 100, representing the size of the matrix.
2. The next n lines contain n integers each, representing the elements of the matrix.

Output:
Print a single integer which is the sum of left diagonal and right diagonal elements.

Example input
3
1 2 3
4 5 6
7 8 9

Output:
30

Explanation
left diagonal: 1 + 5 + 9 = 15
right diagonal: 3 + 5 + 7 = 15
total sum = 15 + 15 = 30*/



#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> matrix;

public:
    SquareMatrix(int size) : n(size) {
        matrix.resize(n, vector<int>(n));
    }

    void inputMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
    }


    int calculateDiagonalSum() const {
        if(n == 1) {
            return matrix[0][0];
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][i] + matrix[i][n - 1 - i];
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;

    SquareMatrix mat(n);
    mat.inputMatrix();
    cout << mat.calculateDiagonalSum();

    return 0;
}