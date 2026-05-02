#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    vector<vector<int>> adj={{1,2,3}, {4}, {4,5}, {5}, {6}, {6}, {}};
    int V=adj.size();
    vector<vector<int>> res(V);
    set<int> st;
    queue<pair<int, int>> q;
    q.push({0, 0});
    st.insert(0);
    res[0]={0};
    while (!q.empty()) {
        auto ele=q.front();
        q.pop();
        int lvl=ele.first;
        int node=ele.second;
        for (auto it: adj[node]) {
            q.push({lvl+1, it});
            if (st.find(it)==st.end()) {
                res[lvl+1].push_back(it);
                st.insert(it);
            }
        }
    }
    int sz=1;
    for (int i=0; i<res.size(); i++) {
        if (res[i].size()!=0) {
            cout << "Stage: " << sz << endl;
            for (auto it: res[i]) {
                cout << it << " ";
            }
            sz++;
        }   
        cout << endl;
    }
}