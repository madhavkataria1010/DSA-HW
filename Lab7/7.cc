/*You are given a directed, weighted graph representing a network of n nodes, labeled from 1 to n. The graph is given as an array times, where each element (u, v, w) represents a directed edge from node u to node v with a transmission time of w units.

A signal is sent from a starting node k, and it travels through the network along the given edges. Your task is to determine the minimum time required for all n nodes to receive the signal.

If there exists a node that cannot receive the signal, return -1.

Input Format:
An integer 'n' representing the number of nodes in the network.
An integer 'k' representing the starting node.
An integer 'e' representing the number of directed edges in the network.

Case1:

4 2
3
2 1 1
2 3 1
3 4 1

first line contains :  n and k
second line contains : e
rest all line contains : u v w

output :-
2*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits> // Ensure INT_MAX is recognized

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto& time : times) {
        graph[time[0]].push_back({time[1], time[2]});
    }
    
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    
    while (!pq.empty()) {
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (time > dist[node]) continue;
        
        for (const auto& neighbor : graph[node]) {
            int v = neighbor.first;
            int w = neighbor.second;
            
            if (dist[node] + w < dist[v]) {
                dist[v] = dist[node] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        maxTime = max(maxTime, dist[i]);
    }
    return maxTime;
}

int main() {
    int n, k, e;
    
    // cout << "Enter number of nodes and starting node (n k): ";
    cin >> n >> k;

    // cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> times(e, vector<int>(3));
    
    // cout << "Enter " << e << " edges in the format (u v w):\n";
    for (int i = 0; i < e; i++) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    int result = networkDelayTime(times, n, k);
    cout << result << endl;

    return 0;
}