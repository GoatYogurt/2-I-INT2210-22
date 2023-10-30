#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int u;
    int v;
    int d;

    edge(int a, int b, int c) {
        u = a;
        v = b;
        d = c;
    }
};

bool test(edge a, edge b) {
    return a.d > b.d;
}

int main() {
    ifstream input("connection.txt");
    ofstream output("connection.out");

    int m, n;
    input >> n >> m;

    bool isVisited[n + 1];
    int graph[n + 1][n + 1];
    vector<edge*> edges;

    while (m--) {
        int u, v, d;
        input >> u >> v >> d;
        edges.push_back(new edge(u, v, d));
    }
}
