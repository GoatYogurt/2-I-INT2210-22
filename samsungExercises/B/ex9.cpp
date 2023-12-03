#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    bool isEulerianCycle();
    bool isSC();
    void DFS(int v, vector<bool>& visited);
    void findEulerianCycle(int start, vector<int>& circuit);

    vector<int> getEulerianCycle();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

bool Graph::isEulerianCycle() {
    if (!isSC())
        return false;

    for (int i = 0; i < V; ++i) {
        if (adj[i].size() != adj[i].size())
            return false;
    }

    return true;
}

bool Graph::isSC() {
    vector<bool> visited(V, false);
    DFS(0, visited);

    for (int i = 0; i < V; ++i) {
        if (!visited[i])
            return false;
    }

    Graph gr(V);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            gr.addEdge(v, u);
        }
    }

    fill(visited.begin(), visited.end(), false);
    gr.DFS(0, visited);

    for (int i = 0; i < V; ++i) {
        if (!visited[i])
            return false;
    }

    return true;
}

void Graph::DFS(int v, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            DFS(u, visited);
    }
}

void Graph::findEulerianCycle(int start, vector<int>& circuit) {
    stack<int> path;
    path.push(start);

    while (!path.empty()) {
        int u = path.top();

        if (!adj[u].empty()) {
            path.push(adj[u].back());
            adj[u].pop_back();
        } else {
            circuit.push_back(u);
            path.pop();
        }
    }

    reverse(circuit.begin(), circuit.end());
}

vector<int> Graph::getEulerianCycle() {
    vector<int> circuit;

    if (!isEulerianCycle()) {
        cout << "Khong ton tai chu trinh Euler." << endl;
        return circuit;
    }

    int start = 0;
    findEulerianCycle(start, circuit);

    return circuit;
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 2);

    vector<int> eulerianCycle = g.getEulerianCycle();

    if (!eulerianCycle.empty()) {
        cout << "Chu trinh Euler: ";
        for (int v : eulerianCycle) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
