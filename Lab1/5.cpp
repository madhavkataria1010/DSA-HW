/*Write a  program (not function) to find the set exclusive-or of two arrays.
Note: set exclusive-or of two arrays is the sorted 1D array of unique values that are in only one of the input arrays.
Both arrays has equal size.

Input Format: 
1. The first line contains an integer N, the size of the arrays.
2. The second line contains N space-separated integers for the first array.
3. The third line contains N space-separated integers for the second array.

Output Format: 
A single line containing the space-separated integers of the symmetric difference (set-exclusive or) of the two arrays. The integers should be sorted in ascending order.

Sample Input: 
4
1 2 3 4
2 3 4 5
Sample Output:
1 5*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int size1; cin>>size1;
	int size2 = size1;
	vector<int> A(size1);
	vector<int> B(size2);

	for (int i = 0; i < size1; i++) cin>>A[i];
    for (int i = 0; i < size2; i++) cin>>B[i];


    //write your code here
    set<int> sA(A.begin(), A.end());
    set<int> sB(B.begin(), B.end());

    vector<int> result;
    for(auto &x : sA) if(sB.find(x) == sB.end()) result.push_back(x);
    for(auto &x : sB) if(sA.find(x) == sA.end()) result.push_back(x);

    sort(result.begin(), result.end());
    for(int i = 0; i < (int)result.size(); i++){
        cout << result[i];
        if(i < (int)result.size() - 1) cout << " ";
    }
    
    return 0;
}