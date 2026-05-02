#include <bits/stdc++.h>
using namespace std;

bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[vertex][i] && c == color[i])
            return false;
    }
    return true;
}

bool colorGraphUtil(vector<vector<int>>& graph, int m, vector<int>& color, int vertex) {
    if (vertex == graph.size())
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, graph, color, c)) {
            color[vertex] = c;
            
            if (colorGraphUtil(graph, m, color, vertex + 1))
                return true;
            
            color[vertex] = 0;
        }
    }
    return false;
}

void colorGraph(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> color(n, 0);
    
    if (colorGraphUtil(graph, m, color, 0)) {
        cout << "Graph coloring is possible:\n";
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " -> Color " << color[i] << "\n";
        }
    } else {
        cout << "Not possible to color the graph with " << m << " colors\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;
    
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    colorGraph(graph, m);
    
    return 0;
}
