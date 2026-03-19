#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 means no edge, non-zero means edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int source = 0;
    int destination = n - 1;

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] != 0) {
                indegree[j]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    if ((int)topo.size() != n) {
        cout << "The graph contains a cycle. Multistage graph must be a DAG.\n";
        return 0;
    }

    const int NEG_INF = -1000000000;
    vector<int> longestEdgesFromSource(n, NEG_INF);
    longestEdgesFromSource[source] = 0;

    for (int u : topo) {
        if (longestEdgesFromSource[u] == NEG_INF) {
            continue;
        }
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0) {
                longestEdgesFromSource[v] = max(
                    longestEdgesFromSource[v],
                    longestEdgesFromSource[u] + 1
                );
            }
        }
    }

    if (longestEdgesFromSource[destination] == NEG_INF) {
        cout << "No path exists from source (0) to destination (" << destination << ").\n";
        return 0;
    }

    int stageCount = longestEdgesFromSource[destination] + 1;
    cout << "Number of stages in the multistage graph: " << stageCount << "\n";

    return 0;
}
