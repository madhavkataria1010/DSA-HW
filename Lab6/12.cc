#include <bits/stdc++.h>
using namespace std;

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int,int>> engineers;
    for (int i = 0; i < n; i++) {
        engineers.push_back({efficiency[i], speed[i]});
    }
    sort(engineers.rbegin(), engineers.rend());

    long long maxPerf = 0, speedSum = 0;
    priority_queue<int, vector<int>, greater<int>> speedHeap;
    for (auto& eng : engineers) {
        int currEfficiency = eng.first;
        int currSpeed = eng.second;
        speedSum += currSpeed;
        speedHeap.push(currSpeed);
        if (speedHeap.size() > k) {
            speedSum -= speedHeap.top();
            speedHeap.pop();
        }
        maxPerf = max(maxPerf, speedSum * currEfficiency);
    }
    return (int)maxPerf;
}

int main() {
    int n, k; 
    cin >> n >> k;
    vector<int> speed(n), efficiency(n);
    
    for (int i = 0; i < n; i++) 
        cin >> speed[i];
    for (int i = 0; i < n; i++) 
        cin >> efficiency[i];

    cout << maxPerformance(n, speed, efficiency, k) << endl;
}