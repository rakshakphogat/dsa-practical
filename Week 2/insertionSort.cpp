#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n=arr.size();
    for (int j=1; j<n; j++) {
        int key=arr[j];
        int i=j-1;
        while (i>0 && arr[i]>key) {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
    // for (int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues={1000, 1500, 2500, 3500, 4500, 5500, 6500, 7500, 8500, 9500};
    cout << "Insertion Sort - Time Analysis\n";
    for (int i=0; i<10; i++) {
        int n=testValues[i];
        vector<int> arr(n);
        for (int k=0; k<n; k++) {
            arr[k]=k+1;
        }
        double timeTaken=0;
        for (int iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            insertionSort(arr);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            timeTaken+=duration.count();
        }
        double avgTime=timeTaken/10.0;
        cout << "Array size: " << n << " | Average Time: " << avgTime << "microseconds\n";
    }
}