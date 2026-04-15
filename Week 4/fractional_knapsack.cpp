#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

using Item = pair<int, int>;

double take_fractional_items(const vector<Item>& items, int capacity) {
    double total_profit = 0.0;
    for (const auto& item : items) {
        if (capacity <= 0) {
            break;
        }
        int profit = item.first;
        int weight = item.second;
        if (capacity >= weight) {
            total_profit += profit;
            capacity -= weight;
        } else {
            total_profit += static_cast<double>(profit) * capacity / weight;
            capacity = 0;
        }
    }
    return total_profit;
}


double sorting_by_profit_to_weight_ratio(vector<Item> items, int n, int M) {
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });
    return take_fractional_items(items, M);
}

int main() {
    vector<long long> testValues={100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    cout << fixed << setprecision(2);
    cout << "Fractional Knapsack - Time Analysis\n";
    double sink = 0.0;
    for (long long i=0; i<10; i++) {
        long long n=testValues[i];
        vector<Item> items(n);
        srand(time(0)+i);
        for (long long k=0; k<n; k++) {
            items[k].first = rand()%1000+1;  // profit
            items[k].second = rand()%100+1;  // weight
        }
        int M = rand()%5000+1000;  // knapsack capacity
        double weightTime=0;
        double profitTime=0;
        double ratioTime=0;
        for (long long iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            double ratioResult = sorting_by_profit_to_weight_ratio(items, n, M);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            ratioTime += duration.count();
            sink += ratioResult;
        }
        cout << n << "-" << ratioTime/10.0 << "\n";
    }
    if (sink < 0) {
        cout << sink << endl;
    }
    cout << endl;
}