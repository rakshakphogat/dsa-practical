#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

int findMissingNumber(vector<int> &arr, int n) {
    for (int i=1; i<n; i++) {
        if (arr[i]-arr[i-1]!=1) {
            return arr[i-1]+1;
        }
    }
    return n+1;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues={1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    cout << "Missing Number - Time Analysis\n";
    for (int i=0; i<10; i++) {
        int n = testValues[i];
        vector<int> arr(n);
        for (int k=0; k<n; k++) {
            arr[k]=k+1;
        }
        double totalTime=0.0;
        for (int iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            int result=findMissingNumber(arr, n);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end - start;
            timings[i][iter]=duration.count();
            totalTime+=duration.count();
        }
        double avgTime=totalTime/10.0;
        cout << "Array Size: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
    // for (int i=0; i<10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j=0; j<10; j++) {
    //         cout << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
