#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    
    bool isZero = true;
    for (int i = 0; i < n && isZero; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] != 0){
                isZero = false;
                break;
            }
        }
    }
    
    if(isZero) {
        cout << 0;
        return 0;
    }
    
    // Check for ones matrix: all elements must be 1.
    bool isOnes = true;
    for (int i = 0; i < n && isOnes; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] != 1){
                isOnes = false;
                break;
            }
        }
    }
    
    if(isOnes){
        cout << 1;
        return 0;
    }
    

    bool isIdentity = true;
    if(n != m){
        isIdentity = false;
    }
    else {
        for (int i = 0; i < n && isIdentity; i++){
            for (int j = 0; j < m; j++){
                if(i == j){
                    if(matrix[i][j] != 1){
                        isIdentity = false;
                        break;
                    }
                } else {
                    if(matrix[i][j] != 0){
                        isIdentity = false;
                        break;
                    }
                }
            }
        }
    }
    
    if(isIdentity){
        cout << 2;
        return 0;
    }
    
    cout << -1;
    return 0;
}