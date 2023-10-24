#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int countConnectedComponents(int n) {
    int connectedComponents = 0;
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            connectedComponents++;
        }
    }

    return connectedComponents;
}

int main() {
    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int numConnectedComponents = countConnectedComponents(n);
    cout << numConnectedComponents << endl;

    return 0;
}
