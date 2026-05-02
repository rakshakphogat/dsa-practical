#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;
    
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    
    return true;
}

bool hamiltonianUtil(vector<vector<int>>& graph, vector<int>& path, int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    
    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            
            if (hamiltonianUtil(graph, path, pos + 1, n))
                return true;
            
            path[pos] = -1;
        }
    }
    
    return false;
}

void hamiltonianCycle(vector<vector<int>>& graph, int n) {
    vector<int> path(n, -1);
    path[0] = 0;
    
    if (hamiltonianUtil(graph, path, 1, n)) {
        cout << "Hamiltonian cycle exists:\n";
        for (int i = 0; i < n; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << "\n";
    } else {
        cout << "No Hamiltonian cycle exists\n";
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    hamiltonianCycle(graph, n);
    
    return 0;
}
