/*You are given a grid of size ‘4 x N’ and boxes of size (1 x 4) and (4 x 1). You have to fill the grid with these boxes. Write a function grid(n) which will take n as an argument and return the total number of ways you can fill the grid using boxes of given size.

Input format:
There's a single line input which contains the integer n.
Constraints: n > 0

Output format:
There should be single line output containing the answer integer


Sample Test Case:
Input:
4
Output:
2

Explanation: The size of the grid is 4 x 4, and there are only two ways to fill the grid. 
Either arrange all boxes of size (4 x 1) vertically or arrange boxes of size (1 x 4) horizontally.*/


#include <iostream>

using namespace std;


int grid(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    return grid(n-1) + grid(n-4);
}

int main(){
    // There's no need to change this
    int n; cin>>n;
    cout<<grid(n);
}