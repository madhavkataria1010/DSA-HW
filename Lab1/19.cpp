/*Write a function that generates an  n×n matrix filled with a specific pattern using the character #
1.The first and last rows are entirely filled with #.
2.The first and last columns are filled with #.
3.The two diagonals of the matrix (from top-left to bottom-right and from top-right to bottom-left) are filled with #.
4. All other positions in the matrix should be filled with spaces  ' '
Input: n
output: n×n matrix 

Example: for n=7
#######
##   ##
# # # #
#  #  #
# # # #
##   ##
#######*/

#include <iostream>
#include <vector>

using namespace std;


vector<vector<char>> fillHashPatt(int n) {
    // Your code here
    vector<vector<char>> result(n, vector<char>(n, ' '));
    for(int i = 0; i < n; i++){
        result[0][i] = '#';
        result[n - 1][i] = '#';
        result[i][0] = '#';
        result[i][n - 1] = '#';
        result[i][i] = '#';
        result[i][n - i - 1] = '#';
    }
    return result;

    
}

int main() {
    int n;
    
    // Taking input for the size of the matrix
    cin >> n;
    
    // Function call to generate the matrix pattern
    vector<vector<char>> result = fillHashPatt(n);
    
    // Printing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    
    return 0;
}