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