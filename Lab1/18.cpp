/*Write the body of the function that takes a matrix as an input, and return a tuple having sums of the upper-triangular and lower triangular matrices.

Sample Input:
3
6 5 4
1 2 5
7 9 7

Sample Output:
29 32

Explanation:
Since, for the given input matrix, the upper-triangular matrix is:  
    [[6, 5, 4],
     [0, 2, 5],
     [0, 0, 7]] => Sum = (6 + 5 + 4 + 0 + 2 + 5 + 0 + 0 + 7) = 29
and, the lower triangular matrix is: 
    [[6, 0, 0],
     [1, 2, 0],
     [7, 9, 7]] => Sum = (6 + 0 + 0 + 1 + 2 + 0 + 7 + 9 + 7) = 32

Thus, the output 29 32*/


#include <iostream>  
using namespace std;  
int main() {
   //code
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int upper = 0, lower = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j) upper += arr[i][j];
            if(i>=j) lower += arr[i][j];
        }
    }
    cout << upper << ' ' << lower;
    return 0;
}