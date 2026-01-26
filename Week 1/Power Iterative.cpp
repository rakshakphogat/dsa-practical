#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

double powerIterative(double x, int n) {
    double result = 1.0;
    int absN = abs(n);
    for (int i = 0; i < absN; i++) {
        result *= x;
    }
    return n < 0 ? 1.0 / result : result;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    int testValues[] = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    double x = 2.0;
    cout << "Power Iterative - Time Analysis\n";
    for (int i = 0; i < 10; i++) {
        int n = testValues[i];
        double totalTime = 0.0;
        for (int iter = 0; iter < 10; iter++) {
            auto start = chrono::high_resolution_clock::now();
            double result = powerIterative(x, n);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration = end - start;
            timings[i][iter] = duration.count();
            totalTime += duration.count();
        }
        double avgTime = totalTime / 10.0;
        cout << "Exponent: " << setw(4) << n << " | Average Time: " << fixed << setprecision(2) << avgTime << " microseconds\n";
    }
    // for (int i = 0; i < 10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j = 0; j < 10; j++) {
    //         cout << fixed << setprecision(2) << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
