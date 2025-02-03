/*Given a matrix M, return the sum of the + path from it. 
Note: The number of rows and columns in the array is odd.

Input:
The first line consists of 2 space-separated integers n(1 <= n < 100) & m(1 <= m < 100). The next n lines contain m space-separated integers, the elements of the array.

Output:
Print a single integer which is the sum of the + path.

Sample Input 1:
5 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

Sample Output 1:
27

Explanation: The + sign means the elements in the middle of the rows and columns, thus 3 + 3 + 3 + 3 + 1 + 2 + 3 + 4 + 5 = 27*/



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
        //write your code here, return the answer in the end.
        int sum = 0;
        for(int i=0;i<mat.n;i++) sum += mat.M[i][mat.m/2];
        for(int i=0;i<mat.m;i++) sum += mat.M[mat.n/2][i];
        return sum - mat.M[mat.n/2][mat.m/2];
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin >> n >> m;
    matrix mat(n,m);
    
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> mat.M[i][j];

    solution sol;
    cout << sol.solve(mat);

    return 0;
}