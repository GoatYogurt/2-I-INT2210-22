#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ofstream output("output.txt");
    ifstream input("input.txt");

    vector<vector<int>> adj;
    int v, e;
    input >> v >> e;
    int parallel[100][100] = {0};
    
    adj.resize(v);

    // vertex must be 0-indexed
    for (int i = 1; i <= e; ++i) {
        int a, b;
        input >> a >> b;
        adj.at(a).push_back(b);
    }

    for (int i = 0; i < v; ++i) {
        for (auto neighbor : adj.at(i)) {
            parallel[i][neighbor]++;
            parallel[neighbor][i]++;
        }
    }

    int count = 0;
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (parallel[i][j] >= 2) {
                count += parallel[i][j] - 1;
            }
        }
    }

    output << count / 2 << endl;
}