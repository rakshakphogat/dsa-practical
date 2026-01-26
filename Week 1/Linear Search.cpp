#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    int testValues[] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    cout << "Linear Search - Time Analysis\n";
    for (int i = 0; i < 10; i++) {
        int n = testValues[i];
        int* arr = new int[n];
        for (int k = 0; k < n; k++) {
            arr[k] = k + 1;
        }
        int target = n;
        double totalTime = 0.0;
        for (int iter = 0; iter < 10; iter++) {
            auto start = chrono::high_resolution_clock::now();
            int result = linearSearch(arr, n, target);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration = end - start;
            timings[i][iter] = duration.count();
            totalTime += duration.count();
        }
        double avgTime = totalTime / 10.0;
        cout << "Array Size: " << setw(5) << n << " | Average Time: " << fixed << setprecision(2) << avgTime << " microseconds\n";
        delete[] arr;
    }
    // for (int i = 0; i < 10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j = 0; j < 10; j++) {
    //         cout << fixed << setprecision(2) << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
