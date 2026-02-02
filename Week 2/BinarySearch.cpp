#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

long long binarySearch(vector<long long> &arr, long long low, long long high, long long target) {
    if (low>high) return -1;
    long long mid=(low+high)/2;
    if (arr[mid]==target) return mid;
    else if (arr[mid]>target) return binarySearch(arr, low, mid-1, target);
    else return binarySearch(arr, mid+1, high, target);
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<long long> testValues={1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    cout << "Binary Search - Time Analysis\n";
    for (long long i=0; i<10; i++) {
        long long n=testValues[i];
        vector<long long> arr(n);
        for (long long k=0; k<n; k++) {
            arr[k]=k+1;
        }
        double timeTaken=0;
        long long result=0;
        for (long long iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            result=binarySearch(arr, 0, n-1, arr[0]);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            timeTaken+=duration.count();
        }
        if (result==-1) {
        cout << "Element not found" << endl;
        } else {
            cout << "Element found at index: " << result << endl;
        }
        double avgTime=timeTaken/10.0;
        cout << "Array Size: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
}