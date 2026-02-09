#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(vector<long long> &arr, int lo, int mid, int hi) {
    vector<int> temp;
    int l=lo, r=mid+1;
    while (l<=mid && r<=hi) {
        if (arr[l]>=arr[r]) {
            temp.push_back(arr[r++]);
        } else {
            temp.push_back(arr[l++]);
        }
    }
    while (l<=mid) {
        temp.push_back(arr[l++]);
    }
    while (r<=hi) {
        temp.push_back(arr[r++]);
    }
    for (int i=lo; i<=hi; i++) {
        arr[i]=temp[i-lo];
    }
}

void mergeSort(vector<long long> &arr, int lo, int hi) {
    if (lo>=hi) return;
    int mid=(lo+hi)/2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}

int main() {
	// your code goes here
    vector<vector<double>> timings(10, vector<double>(10));
    vector<long long> testValues={1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    cout << "Merge Sort - Time Analysis\n";
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
            mergeSort(arr, 0, n-1);
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
