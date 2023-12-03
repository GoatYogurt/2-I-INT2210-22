#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
    int label;
    vector<int> neighbors;
};

vector<int> topologicalSort(vector<Vertex>& graph) {
    int V = graph.size();
    vector<int> indegree(V, 0);
    queue<int> q;

    for (int i = 0; i < V; ++i) {
        for (int neighbor : graph[i].neighbors) {
            indegree[neighbor]++;
        }
    }

    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int neighbor : graph[u].neighbors) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    int V = 6;
    vector<Vertex> graph(V);

    graph[0].label = 0; graph[0].neighbors = {1, 2};
    graph[1].label = 1; graph
