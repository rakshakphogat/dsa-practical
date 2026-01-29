#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void permutationGenerationOfString(int n, int idx, string &s) {
    if (idx==n) return;
    for (int i=idx; i<n; i++) {
        swap(s[i], s[idx]);
        permutationGenerationOfString(n, idx + 1, s);
        swap(s[i], s[idx]);
    }
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<string> testStrings = {"ab", "abc", "abcd", "abcde", "abcdef", "abcdefg", "abcdefgh", "abcdefghi", "abcdefghij", "abcdefghijk"};
    vector<int> safeLengths = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10};
    cout << "Permutation Generation of String - Time Analysis\n";
    for (int i=0; i<10; i++) {
        string s=testStrings[safeLengths[i]-2];
        int n=s.length();
        double totalTime=0.0;
        for (int iter=0; iter<10; iter++) {
            string temp=s;
            auto start=chrono::high_resolution_clock::now();
            permutationGenerationOfString(n, 0, temp);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            totalTime+=duration.count();
        }
        double avgTime=totalTime/10.0;
        cout << "String Length: " << n << " | Average Time: " << avgTime << " microseconds\n";
    }
    // for (int i=0; i<10; i++) {
    //     cout << "Length " << testStrings[i].length() << ": ";
    //     for (int j=0; j<10; j++) {
    //         cout << timings[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}