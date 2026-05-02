#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INF = 1e9;

int main() {
    int V, E;
    cin >> V >> E;
    int src, dest;
    cin >> src >> dest;
    vector<vector<int>> graph(V+1, vector<int>(V+1, INF));
    vector<vector<int>> path(V+1, vector<int>(V+1, -1));
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        path[u][v] = v;
    }
    for (int i = 1; i <= V; i++) {
        graph[i][i]=0;
        path[i][i]=i;
    }
    vector<vector<int>> dist = graph;
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    if (path[src][dest] == -1) {
        cout << "No path from " << src << " to " << dest << endl;
    } else {
        cout << "Path from " << src << " to " << dest << ": ";
        int u = src;
        cout << u << " ";
        while (u != dest) {
            u = path[u][dest];
            cout << u << " ";
        }
        cout << endl;
    }
    cout << endl;
}
