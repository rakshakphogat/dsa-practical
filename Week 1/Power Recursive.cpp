#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

double powerRecursive(double x, int n) {
    if (n == 0) return 1.0;
    if (n < 0) return 1.0 / powerRecursive(x, -n);
    double half = powerRecursive(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    int testValues[] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    double x = 2.0;
    cout << "Power Recursive - Time Analysis\n";
    for (int i = 0; i < 10; i++) {
        int n = testValues[i];
        double totalTime = 0.0;
        for (int iter = 0; iter < 10; iter++) {
            auto start = chrono::high_resolution_clock::now();
            double result = powerRecursive(x, n);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration = end - start;
            timings[i][iter] = duration.count();
            totalTime += duration.count();
        }
        double avgTime = totalTime / 10.0;
        cout << "Exponent: " << setw(5) << n << " | Average Time: " << fixed << setprecision(2) << avgTime << " microseconds\n";
    }
    // for (int i = 0; i < 10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j = 0; j < 10; j++) {
    //         cout << fixed << setprecision(2) << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
