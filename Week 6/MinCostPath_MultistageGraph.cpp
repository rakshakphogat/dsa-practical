#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int to, weight;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    vector<int> cost(n, INT_MAX);
    vector<int> nextNode(n, -1);
    cost[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        for (auto edge : graph[i]) {
            int v = edge.to;
            int w = edge.weight;
            if (cost[v] != INT_MAX && w + cost[v] < cost[i]) {
                cost[i] = w + cost[v];
                nextNode[i] = v;
            }
        }
    }
    cout << "Minimum Cost: " << cost[0] << endl;
    cout << "Path: ";
    int current = 0;
    while (current != -1) {
        cout << current << " ";
        current = nextNode[current];
    }
    cout << endl;
    return 0;
}