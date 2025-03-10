#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minCostToConnectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());
    int totalCost = 0;

    cout << "Initial Min-Heap: ";
    for (int r : ropes) 
        cout << r << " ";
    cout << "\n\n";

    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int cost = first + second;
        totalCost += cost;
        
        cout << "Connecting ropes " << first << " and " << second << " with cost " << cost << endl;
        
        minHeap.push(cost);
        
        cout << "Updated Min-Heap: ";
        priority_queue<int, vector<int>, greater<int>> tempHeap = minHeap;
        while (!tempHeap.empty()) {
            cout << tempHeap.top() << " ";
            tempHeap.pop();
        }
        cout << "\n\n";
    }
    
    return totalCost;
}

int main() {
    int n;
    cout << "Enter number of ropes: ";
    cin >> n;
    
    vector<int> ropes(n);
    cout << "Enter the lengths of the ropes: ";
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    int totalCost = minCostToConnectRopes(ropes);
    cout << "Minimum total cost to connect all ropes: " << totalCost << endl;
    return 0;
}