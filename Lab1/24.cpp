#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
    int n, m;
    vector<vector<int>> M;
    
    Matrix(int rowsize, int colsize){
        n = rowsize;
        m = colsize;
        M = vector<vector<int>>(n, vector<int>(m, 0));
    }
    
    // Prints the matrix with single-space separated values per row
    void printMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                cout << M[i][j];
                if(j < m - 1) cout << " ";
            }
            cout << "\n";
        }
    }
    
    // Adds k to each element in the submatrix defined by (row1, col1) to (row2, col2)
    void add_k_matrix(int k, int row1, int col1, int row2, int col2) {
        for (int i = row1; i <= row2; i++){
            for (int j = col1; j <= col2; j++){
                M[i][j] += k;
            }
        }
    }
};

int main(){
    int n = 0, m = 0;
    
    // Input n and m
    cin >> n >> m;
    
    // Create matrix of size n x m
    Matrix mat(n, m);
    
    // Input matrix elements
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat.M[i][j];
        }
    }
    
    int k, row1, col1, row2, col2;
    
    // Input the value k and the submatrix boundaries (row1 col1 and row2 col2)
    cin >> k >> row1 >> col1 >> row2 >> col2;
    
    // Apply addition of k to the submatrix
    mat.add_k_matrix(k, row1, col1, row2, col2);
    
    // Print the updated matrix
    mat.printMatrix();
    
    return 0;
}