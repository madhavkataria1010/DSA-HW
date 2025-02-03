/*Given a matrix M, return a array of numbers where the elements of M are arranged in concentric-form.

Input Format - The first line of input will be n , m denoting the number of rows and columns in the matrix. Next n lines in the input will contain m integers each representing the matrix M.

Output Format - Print the concentric-form in a single line with spaces after each element i.e n*m elements in a single line. Please refer to example output or the test case for more clarity.

Example Input - 
2 2 
1 2
3 4

Example Output - 
1 2 4 3 */

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    // Write your code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            cout << matrix[top][i] << " ";
        }
        top++;
        for(int i = top; i <= bottom; i++){
            cout << matrix[i][right] << " ";
        }
        right--;
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    
    

    return 0;
}