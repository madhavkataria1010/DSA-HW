/*Consider a matrix with all elements as zeros. Given n and m are the dimensions of the matrix.  Given the array of indices say 'index' and index[i] = [ni, mi].  For each pair of indices i.e., index[i] given, increment all the values in row ni first, then increment all the values in column mi by 1. Repeat the procedure for all pairs of indices given.
Finally, return the number of elements with even values in the matrix.  

For example: n = 2, m = 3, index = [[0, 1], [1, 1]]. First initialize the matrix to zeros. Then consider [0, 1]. Increment the values along the 0th row. Then, increment the values along the 1st column. The resultant matrix is [[1, 2, 1], [0, 1, 0]]. Now consider the 2nd index [1, 1]. Increment all the values in 1st row, and then increment values in 1st column. The final resultant matrix obtained is [[1, 3, 1], [1, 3, 1]]. So counting the number of even values in the above resultant, it is zero.

Input:
n
m
index_len
index[1,1] index[1,1]
index[2,1] index[2,2]
.
.
.
index[index_len,1] index[index_len,2]

Output:
evenCount

(where evenCount is the required answer)*/

#include <iostream>
#include <vector>
using namespace std;

int IndicesIncrementAndEvenCounter(vector<vector<int>>* index, int n, int m, int index_len){
    
   
    
    bool rows[n] = {false};
    bool cols[m] = {false};
    
    for (int i = 0; i < index_len; i++)
    {
        rows[(*index)[i][0]] ^= true;
        cols[(*index)[i][1]] ^= true;
    }
    
    int rowsEven = 0, colsEven = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (rows[i])
        {
            rowsEven++;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        if (cols[i])
        {
            colsEven++;
        }
    }
    
    return rowsEven*colsEven + (n-rowsEven)*(m-colsEven);
    
    
  
}


int main(){
    int n, m;
    int index_len;
    cin>>n>>m>>index_len;
    
  
    
    vector<vector<int>> index(index_len, vector<int>(2, 0));
    
    for (int i = 0; i < index_len; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>index[i][j];
        }
        
    }
    
    // Write your code for taking input (n,m,ind
 
    int evenCount = IndicesIncrementAndEvenCounter(&index, n, m, index_len);
    cout << evenCount;
    return 0;
}