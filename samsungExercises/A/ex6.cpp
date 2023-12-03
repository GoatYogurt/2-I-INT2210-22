#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
   private:
    int vertices;
    list<int>* adj;
    int time;

   public:
    Graph(int vertices) {
        this->vertices = vertices;
        this->adj = new list<int>[vertices];
        this->time = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isEdgeConnected() {
        vector<bool> visited(vertices, false);
        vector<int> disc(vertices, -1);
        vector<int> low(vertices, -1);

        return isEdgeConnectedUtil(0, visited, disc, low, -1);
    }


    bool isEdgeConnectedUtil(int u, vector<bool>& visited, vector<int>& disc,
                               vector<int>& low, int parent) {
    int children = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            if (isEdgeConnectedUtil(v, visited, disc, low, u)) return true;

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                return true;
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }

    return false;
}
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    if (g.isEdgeConnected()) {
        cout << "The graph is edge-connected." << endl;
    } else {
        cout << "The graph is not edge-connected." << endl;
    }

    return 0;
}
