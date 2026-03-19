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

int prims(vector<vector<Edge>> &graph) {
    int n=graph.size();
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int minCost=0;

    while (!pq.empty()) {
        int weight=pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u]=true;
        minCost+=weight;

        for (auto edge: graph[u]) {
            if (!visited[edge.to]) {
                pq.push({edge.weight, edge.to});
            }
        }
    }
    return minCost;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues={50, 100, 150, 200, 250, 300, 350, 400, 450, 500};
    cout << "Prims Algorithm - Time Analysis\n";
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
            int minCost=prims(graph);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            timeTaken+=duration.count();
        }
        double avgTime=timeTaken/10.0;
        cout << "Vertices: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
}
