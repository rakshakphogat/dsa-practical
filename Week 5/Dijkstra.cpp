#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to, weight;
};

vector<int> dijkstra(vector<vector<Edge>> &graph, int source, vector<int> &parent) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[source] = 0;
    pq.push({0, source});
    parent[source] = -1;

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

void printPath(int v, vector<int> &parent) {
    if (v == -1) return;
    printPath(parent[v], parent);
    cout << v << " ";
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
    int source;
    cin >> source;
    vector<int> parent(n, -1);
    vector<int> dist = dijkstra(graph, source, parent);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "No path to " << i << endl;
        } else {
            cout << "Distance to " << i << " = " << dist[i] << " | Path: ";
            printPath(i, parent);
            cout << endl;
        }
    }
    return 0;
}