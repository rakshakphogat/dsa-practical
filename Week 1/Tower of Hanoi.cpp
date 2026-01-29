#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char use) {
    if (n==1) return;
    towerOfHanoi(n-1, source, use, destination);
    towerOfHanoi(n-1, use, destination, source);
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues = {5, 10, 15, 18, 19, 20, 21, 22, 23, 24};
    cout << "Tower of Hanoi - Time Analysis\n";
    for (int i=0; i<10; i++) {
        int n=testValues[i];
        double totalTime=0.0;
        for (int iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            towerOfHanoi(n, 'A', 'C', 'B');
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            totalTime+=duration.count();
        }
        double avgTime=totalTime/10.0;
        cout << "Disks: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
    // for (int i = 0; i < 10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j = 0; j < 10; j++) {
    //         cout << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
