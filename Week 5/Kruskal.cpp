#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

class DisjointSet {
private:
    vector<int> parent, rankValue;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rankValue.assign(n, 0);
        for (int i=0; i<n; i++) {
            parent[i]=i;
        }
    }
    int findParent(int node) {
        if (parent[node]==node) {
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }

    void unionSet(int u, int v) {
        u=findParent(u);
        v=findParent(v);
        if (u==v) return;
        if (rankValue[u]<rankValue[v]) {
            parent[u]=v;
        } else if (rankValue[u]>rankValue[v]) {
            parent[v]=u;
        } else {
            parent[v]=u;
            rankValue[u]++;
        }
    }
};

int kruskal(vector<Edge> &edges, int n, vector<Edge> &mst) {
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.weight < b.weight;
    });
    DisjointSet ds(n);
    int minCost = 0;
    for (auto edge : edges) {
        if (ds.findParent(edge.u) != ds.findParent(edge.v)) {
            minCost += edge.weight;
            mst.push_back(edge);
            ds.unionSet(edge.u, edge.v);
        }
    }
    return minCost;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<Edge> mst;
    int minCost = kruskal(edges, n, mst);
    cout << "Minimum Cost: " << minCost << endl;
    cout << "Edges in MST:\n";
    for (auto e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    return 0;
}