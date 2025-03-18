/*Problem Statement: Implement a Depth First Search (DFS) traversal algorithm for a graph represented using an adjacency list. The graph can be directed or undirected. Write a C++ program to perform DFS traversal starting from a given node and print the order of visited nodes.

Input Format
1. The first line contains two integers: num_vertices and num_edges, representing the number of vertices and edges in the graph, respectively.
2. The next num_edges lines contain two integers each, representing the source and destination vertices of an edge.
3. The last line contains a single integer, start_node, which is the node from where the DFS traversal should start.

Output Format
Print the order of visited nodes during the DFS traversal, separated by spaces.
*/


#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    graph.resize(num_vertices + 1);
    visited.resize(num_vertices + 1, false);

    for(int i = 0; i < num_edges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
        // For an undirected graph, also add:
        // graph[dest].push_back(src);
    }

    int start_node;
    cin >> start_node;

    dfs(start_node);
    cout << "\n";

    return 0;
}