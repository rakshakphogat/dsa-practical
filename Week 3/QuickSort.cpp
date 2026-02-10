#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<long long> &arr, int lo, int hi) {
    int pivot=arr[hi];
    int i=lo-1;
    for (int j=lo; j<=hi-1; j++) {
        if (arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[hi]);
    return i+1;
}

void quickSort(vector<long long> &arr, int low, int high) {
    if (low<high) {
        int pivot=partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
	// your code goes here
    vector<vector<double>> timings(10, vector<double>(10));
    vector<long long> testValues={1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    cout << "Quick Sort - Time Analysis\n";
    for (long long i=0; i<10; i++) {
        long long n=testValues[i];
        vector<long long> arr(n);
        srand(time(0)+i);
        for (long long k=0; k<n; k++) {
            arr[k]=rand()%1000+1;
        }
        double timeTaken=0;
        for (long long iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            quickSort(arr, 0, n-1);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            timeTaken+=duration.count();
        }
        // for (auto &x: arr) {
        //     cout << x << " ";
        // }
        double avgTime=timeTaken/10.0;
        // cout << "Array Size: " << n << " | Average Time: " << avgTime << " microseconds\n";
        cout << avgTime << ",";
    }
    cout << endl;
}
