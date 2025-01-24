#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix {
public:
    int n, m;
    vvi M;
    matrix(int shape0, int shape1) {
        n = shape0;
        m = shape1;
        M = vvi(n, vi(m, 0));
    }
    void displayMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << M[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

class solution {
public:
    void solve(matrix &mat) {
        int n = mat.n;  // original rows
        int m = mat.m;  // original columns
        
        // Determine which rows are completely zero.
        vector<bool> keepRow(n, true);
        for (int i = 0; i < n; i++) {
            bool allZero = true;
            for (int j = 0; j < m; j++) {
                if(mat.M[i][j] != 0) { 
                    allZero = false;
                    break;
                }
            }
            if(allZero) {
                keepRow[i] = false;
            }
        }
        
        // Determine which columns are completely zero.
        vector<bool> keepCol(m, true);
        for (int j = 0; j < m; j++) {
            bool allZero = true;
            for (int i = 0; i < n; i++) {
                if(mat.M[i][j] != 0) {
                    allZero = false;
                    break;
                }
            }
            if(allZero) {
                keepCol[j] = false;
            }
        }
        
        // Compute the shape of the resulting matrix.
        int new_n = 0, new_m = 0;
        for (int i = 0; i < n; i++) {
            if(keepRow[i])
                new_n++;
        }
        for (int j = 0; j < m; j++) {
            if(keepCol[j])
                new_m++;
        }
        
        // Instantiate a new matrix object with the computed shape.
        matrix newMat(new_n, new_m);
        
        // Fill the new matrix using the rows and columns that are kept.
        int new_i = 0;
        for (int i = 0; i < n; i++) {
            if (!keepRow[i]) continue;
            int new_j = 0;
            for (int j = 0; j < m; j++) {
                if(!keepCol[j]) continue;
                newMat.M[new_i][new_j] = mat.M[i][j];
                new_j++;
            }
            new_i++;
        }
        
        // Call the displayMatrix member of the new matrix.
        newMat.displayMatrix();
    }
};

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    // 1. Instantiate a matrix object with the input shape taken
    int n;
    cin >> n;
    int m = n; // square matrix as assumed
    matrix mat(n, m);
    
    // 2. Use for loop to set its elements
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat.M[i][j];
        }
    }
    
    // 3. Create a solution object and call its member function solve
    solution sol;
    sol.solve(mat);
    
    return 0;
}