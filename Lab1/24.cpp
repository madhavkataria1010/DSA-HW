/* You are given a matrix M of size n x m and a set of numbers k, row1, col1, row2, col2. You have to return M after adding k to the submatrix starting at (row1, col1) and ending at (row2, col2).

E.g.: For a matrix 
M =[
[1, 2, 3],
[1, 1, 0],
[4, -2, -2] ]
with k = 2, (row1,col1) = (0,0), (row2,col2) = (1,1), the new matrix M' becomes:
M' = [
[3, 4, 5],
[3, 3, 0],
[4, -2, -2] ]

Input:
n
m
M[0,0] M[0,1] ... M[0,m-1]
M[1,0] M[1,1] ... M[1,m-1]
.
.
.
M[n-1,0] M[n-1,1] ... M[n-1,m-1]
k
row1 col1
row2 col2

Output:
M'[1,0] M'[1,1] ... M'[1,m-1]
.
.
.
M'[n-1,0] M'[n-1,1] ... M'[n-1,m-1]

(where M' is the updated matrix)

All variables are within CPP bounds for int data type (even after updating the matrix)

Note: The output matrix is to be printed with single-space separated columns, and newline character separated rows (including after the last row) 
*/




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int k, row1, col1, row2, col2;
    cin >> k;
    cin >> row1 >> col1;
    cin >> row2 >> col2;

    int start_row = min(row1, row2);
    int end_row = max(row1, row2);
    int start_col = min(col1, col2);
    int end_col = max(col1, col2);

    for (int i = start_row; i <= end_row; ++i) {
        for (int j = start_col; j <= end_col; ++j) {
            matrix[i][j] += k;
        }
    }

    for (const auto& row : matrix) {
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            // if (j != row.size() - 1) {
                cout << " ";
            // }
        }
        cout << endl;
    }

    return 0;
}