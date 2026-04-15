#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
};

int findStages(int n, vector<Edge>& edges) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for (auto e : edges) {
        adj[e.u].push_back(e.v);
        indegree[e.v]++;
    }
    vector<int> dp(n, 1);
    vector<int> topo;
    vector<bool> visited(n, false);
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) dfs(v);
        }
        topo.push_back(u);
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());
    for (int u : topo) {
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v;
    }
    int stages = findStages(n, edges);
    cout << "Number of stages: " << stages << endl;
    return 0;
}