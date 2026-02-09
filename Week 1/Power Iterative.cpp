#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int powerIterative(int x, int n) {
    int result=1;
    for (int i=0; i<n; i++) {
        result*=x;
    }
    return result;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues={100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    srand(time(0));
    int x = rand() % 9 + 2;
    cout << "Power Iterative - Time Analysis\n";
    cout << "Using base x = " << x << "\n\n";
    for (int i=0; i<10; i++) {
        int n=testValues[i];
        double totalTime=0.0;
        for (int iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            int result=powerIterative(x, n);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            totalTime+=duration.count();
        }
        double avgTime=totalTime/10.0;
        cout << "Exponent: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
    // for (int i=0; i<10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j=0; j<10; j++) {
    //         cout << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
