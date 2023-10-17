#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main() {
    int nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    adj.assign(nodeCount, vector<int>());
    visited.assign(nodeCount, false);

    for (int i = 0; i < edgeCount; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int countCC = 0;
    for (int i = 0; i < nodeCount; ++i) {
        if (!visited[i]) {
            dfs(i);
            countCC++;
        }
    }
    cout << countCC << endl;
    return 0;
}
