#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, dist;
};

int N, M;
vector<vector<char>> labyrinth;
vector<vector<bool>> visited;
int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1};

int findShortestPath(Point start, Point exit) {
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        if (current.x == exit.x && current.y == exit.y) {
            return current.dist;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && 
                !visited[nx][ny] && labyrinth[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny, current.dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;
    labyrinth.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));
    Point start, exit;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'S') {
                start = {i, j, 0};
            } else if (labyrinth[i][j] == 'E') {
                exit = {i, j, 0};
            }
        }
    }
    
    cout << findShortestPath(start, exit) << endl;
    return 0;
}