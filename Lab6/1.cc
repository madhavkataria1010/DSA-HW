
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;
    for (int stone : stones) {
        maxHeap.push(stone);
    }
    
    while (maxHeap.size() > 1) {
        int y = maxHeap.top();
        maxHeap.pop();
        int x = maxHeap.top();
        maxHeap.pop();
        
        if (x != y) {
            maxHeap.push(y - x);
        }
    }
    
    return maxHeap.empty() ? 0 : maxHeap.top();
}

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);
    
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    cout << lastStoneWeight(stones) << endl;
    return 0;
}