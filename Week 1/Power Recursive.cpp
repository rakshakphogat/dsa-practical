#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int powerRecursive(int x, int n) {
    if (n==0) return 1;
    int half=powerRecursive(x, n/2);
    if (n%2==0) {
        return half*half;
    } else {
        return x*half*half;
    }
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues={1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    srand(time(0));
    int x = rand() % 9 + 2;
    cout << "Power Recursive - Time Analysis\n";
    for (int i=0; i<10; i++) {
        int n=testValues[i];
        double totalTime=0.0;
        for (int iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            int result=powerRecursive(x, n);
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
