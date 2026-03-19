#include <iostream>
#include <chrono>
#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Edge {
    int to, weight;
};

vector<int> dijkstra(vector<vector<Edge>> &graph, int source) {
    int n=graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source]=0;
    pq.push({0, source});
    while (!pq.empty()) {
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (d!=dist[u]) {
            continue;
        }
        for (auto edge: graph[u]) {
            int v=edge.to;
            int w=edge.weight;
            if (dist[u]!=INT_MAX && dist[u]+w<dist[v]) {
                dist[v]=dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues={50, 100, 150, 200, 250, 300, 350, 400, 450, 500};
    cout << "Dijkstra Algorithm - Time Analysis\n";
    for (int i=0; i<10; i++) {
        int n=testValues[i];
        vector<vector<Edge>> graph(n);
        srand(time(0)+i);

        for (int j=0; j<n-1; j++) {
            int weight=rand()%100+1;
            graph[j].push_back({j+1, weight});
            graph[j+1].push_back({j, weight});
        }

        int extraEdges=2*n;
        for (int j=0; j<extraEdges; j++) {
            int u=rand()%n;
            int v=rand()%n;
            int weight=rand()%100+1;
            if (u!=v) {
                graph[u].push_back({v, weight});
                graph[v].push_back({u, weight});
            }
        }

        double timeTaken=0.0;
        for (int iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            vector<int> dist=dijkstra(graph, 0);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            timeTaken+=duration.count();
        }
        double avgTime=timeTaken/10.0;
        cout << "Vertices: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
}
