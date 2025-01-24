#include <iostream>
#include <vector>
using namespace std;

void compute_matrix(vector<vector<int>>& M) {
    int n = M.size();
    if(n == 0) return;
    int m = M[0].size();
    
    vector<vector<int>> newMatrix(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int sumRight = 0;
            for (int col = j+1; col < m; col++){
                sumRight += M[i][col];
            }
            int sumBelow = 0;
            for (int row = i+1; row < n; row++){
                for (int col = 0; col < m; col++){
                    sumBelow += M[row][col];
                }
            }
            newMatrix[i][j] = sumRight + sumBelow;
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << newMatrix[i][j];
            if(j != m - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> M(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> M[i][j];
        }
    }
    
    compute_matrix(M);
    
    return 0;
}