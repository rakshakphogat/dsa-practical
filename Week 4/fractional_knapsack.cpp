#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int sorting_by_weights(vector<pair<int, int>> items, int n, int M) {
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second<b.second;
    });
    int total_profit=0;
    for (int i=0; i<n; i++) {
        if (M>=items[i].second) {
            total_profit+= items[i].first;
            M-= items[i].second;
        }
    }
    return total_profit;
}

int sorting_by_profits(vector<pair<int, int>> items, int n, int M) {
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first>b.first;
    });
    int total_profit=0;
    for (int i=0; i<n; i++) {
        if (M>=items[i].second) {
            total_profit+= items[i].first;
            M-= items[i].second;
        } 
    }
    return total_profit;
}

int sorting_by_profit_to_weight_ratio(vector<pair<int, int>> items, int n, int M) {
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });

    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        if (M >= items[i].second) {
            total_profit += items[i].first;
            M -= items[i].second;
        }
    }
    return total_profit;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<long long> testValues={100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    cout << "Fractional Knapsack - Time Analysis (Sort by Weights)\n";
    for (long long i=0; i<10; i++) {
        long long n=testValues[i];
        vector<pair<int, int>> items(n);
        srand(time(0)+i);
        for (long long k=0; k<n; k++) {
            items[k].first = rand()%1000+1;  // profit
            items[k].second = rand()%100+1;  // weight
        }
        int M = rand()%5000+1000;  // knapsack capacity
        double timeTaken=0;
        for (long long iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            int result = sorting_by_profit_to_weight_ratio(items, n, M);
            // int result = sorting_by_weights(items, n, M);
            // int result = sorting_by_profits(items, n, M);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            timeTaken+=duration.count();
        }
        double avgTime=timeTaken/10.0;
        cout << avgTime << ",";
    }
    cout << endl;
}