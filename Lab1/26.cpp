#include <bits/stdc++.h>
using namespace std;

int chess(int n) {
    if(n == 0) return 1; 
    if(n == 1) return 3;  
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 3;
    
    for(int i = 2; i <= n; i++){
        dp[i] = 2 * dp[i-1] + 2 * dp[i-2];
    }
    return dp[n];
}

int main(){
    int n; 
    cin >> n;
    
    cout << chess(n);

    return 0;
}
