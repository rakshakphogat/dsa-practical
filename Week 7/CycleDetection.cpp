#include <iostream>
#include <vector>
using namespace std;

int V;
vector<int> par;

int find(int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}

void Union(int x, int y) {
    par[find(x)] = find(y);
}

int main() {
    cin >> V;
    par.assign(V, 0);
    for (int i = 0; i < V; i++) {
        par[i] = i;
    }
    int E;
    cin >> E;
    bool flag = false;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v)) {
            Union(u, v);
        } else {
            flag = true;
        }
    }
    if (flag) cout << "Cycle Detected" << endl;
    else cout << "No Cycle Found" << endl;
    return 0;
}