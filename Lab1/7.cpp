/*You are given a matrix as input. This matrix contains 0’s and 1’s. Now check all four corners of this matrix. If all the corners contain 1 then the program returns True (print "1") else it returns False (print "0"). If there are no rows present inside the matrix or no four distinct corner elements present, then also the program must return False.

Input Format - The first line of the input contains two integers n and m, denoting the number of rows and columns in the matrix respectively. The next n lines contain m integers each, either 0 or 1.

Output Format - Print "1" if all the four corners of the matrix contain 1's, else print "0".

NOTE: You just need to print "1" or "0" as final output. No extra output is valid.

Sample Input 1 : 
1 0 1
0 0 0
1 1 1
Sample output 1 : 
1

Sample Input 2 : 
1 0 1
0 0 0
1 1 0
Sample Output 2 : 
0*/

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
        if(mat.n < 1 || mat.m < 1) return 0;
        if(mat.M[0][0] == 1 && mat.M[0][mat.m-1] == 1 
           && mat.M[mat.n-1][0] == 1 && mat.M[mat.n-1][mat.m-1] == 1) {
            return 1;
        }
        return 0;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    matrix mat(n,m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat.M[i][j];
        }
    }
    solution sol;
    cout << sol.solve(mat) << "\n";

    return 0;
}