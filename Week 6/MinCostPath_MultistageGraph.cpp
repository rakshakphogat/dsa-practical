#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter cost adjacency matrix (0 means no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int source, destination;
    cout << "Enter source vertex (0-based index): ";
    cin >> source;
    cout << "Enter destination vertex (0-based index): ";
    cin >> destination;

    if (source < 0 || source >= n || destination < 0 || destination >= n) {
        cout << "Invalid source or destination index.\n";
        return 0;
    }

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] != 0) {
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
            if (cost[u][v] != 0) {
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

    const int INF = INT_MAX / 4;
    vector<int> minCostToDest(n, INF);
    vector<int> nextNode(n, -1);
    minCostToDest[destination] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int u = topo[i];
        if (u == destination) {
            continue;
        }

        for (int v = 0; v < n; v++) {
            if (cost[u][v] != 0 && minCostToDest[v] != INF) {
                int candidate = cost[u][v] + minCostToDest[v];
                if (candidate < minCostToDest[u]) {
                    minCostToDest[u] = candidate;
                    nextNode[u] = v;
                }
            }
        }
    }

    if (minCostToDest[source] == INF) {
        cout << "No path exists from source to destination.\n";
        return 0;
    }

    vector<int> path;
    int current = source;
    while (current != -1) {
        path.push_back(current);
        if (current == destination) {
            break;
        }
        current = nextNode[current];
    }

    if (path.empty() || path.back() != destination) {
        cout << "No valid path reconstruction possible.\n";
        return 0;
    }

    cout << "Minimum cost from " << source << " to " << destination << " is: "
         << minCostToDest[source] << "\n";

    cout << "Path (one node selected at each stage): ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 < (int)path.size()) {
            cout << " -> ";
        }
    }
    cout << "\n";

    cout << "Stage-wise node selection:\n";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << "Stage " << (i + 1) << ": Node " << path[i] << "\n";
    }

    return 0;
}
