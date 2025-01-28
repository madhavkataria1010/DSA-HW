/*Given a matrix M, return the sum of the I path from it. Complete the function isum to implement this functionality.
Input Format: - First line states the value of N and M, which indicates N*M matrix. (M is odd).
Followed by N lines each containing M integers. 


Example:
Given, matrix :
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
Output : 39
Explanation : I shape is formed by top row(1+2+3+4+5) + bottom row(1+2+3+4+5) + middle column(3+3+3) = 15 + 15 + 9 = 39*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix{
public:
    int n,m;
    vvi M;
    matrix(int shape0, int shape1){
        n = shape0;
        m = shape1;
        M = vvi(n,vi(m,0));
    }
    void displayMatrix(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }
};

class solution{
public:
    int solve(matrix& mat){
        int sumVal = 0;
        // sum top row
        for(int j=0; j<mat.m; j++){
            sumVal += mat.M[0][j];
        }
        // sum bottom row
        for(int j=0; j<mat.m; j++){
            sumVal += mat.M[mat.n - 1][j];
        }
        // sum middle column (excluding top & bottom)
        int mid = mat.m / 2;
        for(int i=1; i<mat.n - 1; i++){
            sumVal += mat.M[i][mid];
        }
        return sumVal;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    matrix mat(n, m);
    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            cin >> mat.M[i][j];
        }
    }
    solution s;
    cout << s.solve(mat);

    return 0;
}