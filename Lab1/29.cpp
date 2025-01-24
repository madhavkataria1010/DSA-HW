#include<bits/stdc++.h>
using namespace std;

int main(){
    int size1; 
    cin >> size1;
    vector<int> A(size1);
    for (int i = 0; i < size1; i++) 
        cin >> A[i];
    
    for (int i = 0; i < size1; i++) {
        for (int j = 7; j >= 0; j--) {
            int bit = (A[i] >> j) & 1;
            cout << bit << " ";
        }
        cout << "\n";
    }
    
    return 0;
}