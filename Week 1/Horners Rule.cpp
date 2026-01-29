#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

double hornersRule(vector<double> &coefficients, int n, double x, int ind) {
    if (ind==n-1) return coefficients[ind];
    return coefficients[ind]+x*hornersRule(coefficients, n, x, ind+1);
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues={100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    double x=2.5;
    cout << "Horner's Rule - Time Analysis\n";
    for (int i=0; i<10; i++) {
        int n=testValues[i];
        vector<double> coefficients(n+1, 1.5);
        double totalTime=0.0;
        for (int iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            double result=hornersRule(coefficients, n, x, 0);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            totalTime+=duration.count();
        }
        double avgTime=totalTime/10.0;
        cout << "Degree: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
    // for (int i=0; i<10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j=0; j<10; j++) {
    //         cout << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
