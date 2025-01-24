#include<bits/stdc++.h>
using namespace std;

int main(){
    int size1; 
    cin >> size1;
    int size2 = size1;

    vector<int> A(size1);
    vector<int> B(size2);

    for (int i = 0; i < size1; i++) cin >> A[i];
    for (int i = 0; i < size2; i++) cin >> B[i];

    unordered_set<int> setA(A.begin(), A.end());
    unordered_set<int> setB(B.begin(), B.end());

    vector<int> difference_A_B; 
    vector<int> difference_B_A; 

    for (int x : setA) {
        if (setB.find(x) == setB.end()) {
            difference_A_B.push_back(x);
        }
    }

    for (int x : setB) {
        if (setA.find(x) == setA.end()) {
            difference_B_A.push_back(x);
        }
    }

    sort(difference_A_B.begin(), difference_A_B.end());
    sort(difference_B_A.begin(), difference_B_A.end());

    for (int x : difference_A_B) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : difference_B_A) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
