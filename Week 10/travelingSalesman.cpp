#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INF=1e9;

int n;
vector<vector<int>> dist;
map<pair<int, set<int>>, int> dp;

int g(int i, set<int> S) {
    if (S.empty()) {
        return dist[i][0];
    }
    if (dp.find({i, S}) != dp.end()) {
        return dp[{i, S}];
    }
    int ans = INF;
    for (int j : S) {
        set<int> nextS = S;
        nextS.erase(j);
        int cost = dist[i][j] + g(j, nextS);
        ans = min(ans, cost);
    }
    return dp[{i, S}] = ans;
}

int main() {
    n = 4;
    dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    set<int> S;
    for (int i = 1; i < n; i++) {
        S.insert(i);
    }
    int result = g(0, S);
    cout << "Minimum TSP cost: " << result << endl;
}