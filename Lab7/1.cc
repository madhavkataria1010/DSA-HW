/*Write a C++ program that performs Breadth-First Search (BFS) on a graph with 7 nodes.
Input Specifications:
The first input should be the number of edges in the graph.
The next set of inputs should contain pairs of integers representing the edges in the format (source destination).
Finally, input the starting vertex from which BFS traversal should begin.
Output: The program should correctly traverse the graph using BFS starting from the given starting vertex (no output for visited nodes in this case).
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int nodes;
    vector<vector<int>> adjList;
    
public:
    Graph(int n) {
        nodes = n;
        adjList.resize(n);
    }
    
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); 
    }
    
    void BFS(int startVertex) {
        vector<bool> visited(nodes, false);
        queue<int> q;
        
        visited[startVertex] = true;
        q.push(startVertex);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            cout << current << " ";
            
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int edges;
    cin >> edges;
    
    Graph g(7); 
    
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
    
    int startVertex;
    cin >> startVertex;
    
    g.BFS(startVertex);
    cout << endl;
    
    return 0;
}