#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void permutationGenerationOfBinaryString(int n, int idx, string &current) {
    if (idx==n) {
        // cout << current << "\n";
        return;
    }
    current[idx]='0';
    permutationGenerationOfBinaryString(n, idx + 1, current);
    current[idx]='1';
    permutationGenerationOfBinaryString(n, idx + 1, current);
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<int> testValues = {5, 8, 10, 12, 14, 16, 18, 20, 21, 23};
    cout << "Permutation Generation of Binary String - Time Analysis\n";
    for (int i=0; i<10; i++) {
        int n=testValues[i];
        double totalTime=0.0;
        for (int iter=0; iter<10; iter++) {
            string temp(n, '0');
            auto start=chrono::high_resolution_clock::now();
            permutationGenerationOfBinaryString(n, 0, temp);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            totalTime+=duration.count();
        }
        double avgTime=totalTime/10.0;
        cout << "String Length: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
    // for (int i=0; i<10; i++) {
    //     cout << "Value " << testValues[i] << ": ";
    //     for (int j=0; j<10; j++) {
    //         cout << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}