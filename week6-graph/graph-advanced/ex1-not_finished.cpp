#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int numOfNode, numOfEdge;
    cin >> numOfNode >> numOfEdge;
    int directedGraph[numOfNode + 1][numOfNode + 1] = {};
    bool isVisited[numOfNode + 1] = {false};
    stack<int> visited;

    for (int i = 1; i <= numOfEdge; ++i) {
        int a, b;
        cin >> a >> b;
        directedGraph[a][b] = 1;
    }

    visited.push(2);
    isVisited[2] = true;
    int currentNode;

    while (!visited.empty()) {
        currentNode = visited.top();

        bool hasUnvisitedAdj = false;
        int adjNode = 0;

        for (int i = 1; i <= numOfNode; ++i) {
            if (directedGraph[currentNode][i] == 1 && !isVisited[i]) {
                hasUnvisitedAdj = true;
                adjNode = i;
                break;
            }
        }

        if (hasUnvisitedAdj) {
            visited.push(adjNode);
            isVisited[adjNode] = true;
        } else {
            visited.pop();
        }
    }

    // for (int i = 1; i <= numOfNode; ++i) {
    //     for (int j = 1; j <= numOfNode; ++j) {
    //         cout << directedGraph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i <= 5; ++i) {
    //     visited.push(i);
    // }
    // cout << visited.size() << endl;
    // cout << findNode(visited, 5) << endl;
    // cout << visited.size();

    return 0;
}
