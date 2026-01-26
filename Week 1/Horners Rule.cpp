#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

double hornersRule(double coefficients[], int n, double x) {
    double result = coefficients[n];
    for (int i = n - 1; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    int testValues[] = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    double x = 2.5;
    cout << "Horner's Rule - Time Analysis\n";
    for (int i = 0; i < 10; i++) {
        int n = testValues[i];
        double* coefficients = new double[n + 1];
        for (int k = 0; k <= n; k++) {
            coefficients[k] = 1.5;
        }
        double totalTime = 0.0;
        for (int iter = 0; iter < 10; iter++) {
            auto start = chrono::high_resolution_clock::now();
            double result = hornersRule(coefficients, n, x);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration = end - start;
            timings[i][iter] = duration.count();
            totalTime += duration.count();
        }
        double avgTime = totalTime / 10.0;
        cout << "Degree: " << n << " | Average Time: " << fixed << setprecision(2) << avgTime << " microseconds\n";
        delete[] coefficients;
    }
    // for (int i = 0; i < 10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j = 0; j < 10; j++) {
    //         cout << fixed << setprecision(2) << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
