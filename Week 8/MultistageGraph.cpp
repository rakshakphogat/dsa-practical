#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std; 

int backwardPropagation(vector<vector<pair<int, int>>> &adj, int n, vector<int> &path) {
    vector<int> dist(n, INT_MAX), parent(n, -1);
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto edge: adj[i]) {
            int v = edge.first, w = edge.second;
            if (dist[i] != INT_MAX && dist[i] + w < dist[v]) {
                dist[v] = dist[i] + w;
                parent[v] = i;
            }
        }
    }
    int curr = n-1;
    cout << "Path: ";
    for (auto x: path) cout << x << " ";
    cout << endl;
    cout << "DIST: ";
    for (auto x: dist) cout << x << " ";
    cout << endl; 
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return dist[n-1];
}

int forwardPropagation(vector<vector<pair<int, int>>> &adj, int n, vector<int> &path) {
    vector<int> dist(n+1, INT_MAX), parent(n, -1);
    dist[n-1] = 0;
    for (int i=n-1; i>=0; i--) {
        for (auto edge: adj[i]) {
            int v = edge.first, w = edge.second;
            if (dist[v] != INT_MAX && dist[v] + w < dist[i]) {
                dist[i] = dist[v] + w;
                parent[i] = v;
            }
        }
    }
    int curr = 0;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return dist[0];
}


int main() {
    int n, m;           // n Vertex, m edges
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> path1, path2;
    vector<vector<pair<int, int>>> adj(n);          // 0 to n-1 vertices
    for (auto edge: edges) {
        int u=edge[0], v=edge[1], w=edge[2];
        adj[u].push_back({v, w});
    }
    int forwardDist = forwardPropagation(adj, n, path1);
    cout << "Forward Distance: " << forwardDist << endl;
    cout << "Forward Path: ";
    for (auto x: path1) cout << x << " ";
    cout << endl;
    cout << endl;

    int backwardDist = backwardPropagation(adj, n, path2);
    cout << "Backward Distance: " << backwardDist << endl;
    cout << "Backward Path: ";
    for (auto x: path2) cout << x << " ";
    cout << endl;
}