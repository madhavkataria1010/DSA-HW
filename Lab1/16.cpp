/*Write a function which takes the matrix as an argument and returns the row sorted matrix. A Row sorted matrix is a matrix in which all the elements in a particular row are sorted in ascending order.

Input Format - The first line of input will be n , m denoting the number of rows and columns in the matrix. Next n lines in the input will contain m integers each representing the matrix M.

Output Format - Print the required matrix in the form given in the input, i.e. n rows containing m integers each.

Example Input - 
2 2 
2 1
2 4
Example Output - 
1 2
2 4*/

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
        void solve(matrix& mat){
            for(auto &row : mat.M){
                sort(row.begin(), row.end());
            }
        }
};

    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        
        int n, m;
        cin >> n >> m;
        matrix mat(n, m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> mat.M[i][j];
            }
        }

        solution sol;
        sol.solve(mat);
        mat.displayMatrix();
    
        return 0;
    }