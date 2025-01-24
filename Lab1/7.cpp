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