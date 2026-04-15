#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to, weight;
};

int prims(vector<vector<Edge>> &graph, vector<pair<int,int>> &mstEdges) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    int minCost = 0;
    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        minCost += weight;
        if (parent[u] != -1) {
            mstEdges.push_back({parent[u], u});
        }
        for (auto edge : graph[u]) {
            if (!visited[edge.to]) {
                pq.push({edge.weight, edge.to});
                parent[edge.to] = u;
            }
        }
    }
    return minCost;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<pair<int,int>> mstEdges;
    int minCost = prims(graph, mstEdges);
    cout << "Minimum Cost: " << minCost << endl;
    cout << "Edges in MST:\n";
    for (auto e : mstEdges) {
        cout << e.first << " - " << e.second << endl;
    }
    return 0;
}