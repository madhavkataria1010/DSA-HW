/*Given a matrix M, replace the elements of the matrix with the sum of all elements to the right of it (in the same row) and all the elements below it. If no elements are present in its right and bottom, then replace it with 0. You have to write a function compute_matrix(M), which will take array as matrix M and print array matrix described above. 

Input Format - The first line of input will be n , m denoting the rows and columns in the matrix. Next n lines in the input will contain m integers each representing the matrix M.

Output Format - Print the required matrix in the form given in the input, i.e. n rows containing m integers each.

Example Input - 
2  2 
1 2
2 4
Example Output - 
8 6
4 0*/

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