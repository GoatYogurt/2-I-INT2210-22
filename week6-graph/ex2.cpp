#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> dist;

int shortestPath(int start, int end) {
    visited.resize(adjList.size(), false);
    dist.assign(adjList.size(), -1);
    
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        for (int neighbor : adjList[currNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                dist[neighbor] = dist[currNode] + 1;
            }
        }
    }

    return dist[end];
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    adjList.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adjList[x].push_back(y);
    }

    int shortestPathLength = shortestPath(X, Y);
    cout << "Number of edges in the shortest path: " << shortestPathLength << endl;

    return 0;
}
