#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Edge {
    int u, v, weight;
};

struct DisjointSet {
    vector<int> parent, rankValue;

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
        if (u==v) {
            return;
        }
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

int kruskal(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.weight<b.weight;
    });

    DisjointSet ds(n);
    int minCost=0;
    for (auto edge: edges) {
        if (ds.findParent(edge.u)!=ds.findParent(edge.v)) {
            minCost+=edge.weight;
            ds.unionSet(edge.u, edge.v);
        }
    }
    return minCost;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues={50, 100, 150, 200, 250, 300, 350, 400, 450, 500};
    cout << "Kruskal Algorithm - Time Analysis\n";
    for (int i=0; i<10; i++) {
        int n=testValues[i];
        vector<Edge> edges;
        srand(time(0)+i);

        for (int j=0; j<n-1; j++) {
            int weight=rand()%100+1;
            edges.push_back({j, j+1, weight});
        }

        int extraEdges=2*n;
        for (int j=0; j<extraEdges; j++) {
            int u=rand()%n;
            int v=rand()%n;
            int weight=rand()%100+1;
            if (u!=v) {
                edges.push_back({u, v, weight});
            }
        }

        double timeTaken=0.0;
        for (int iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            int minCost=kruskal(edges, n);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            timeTaken+=duration.count();
        }
        double avgTime=timeTaken/10.0;
        cout << "Vertices: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
}
