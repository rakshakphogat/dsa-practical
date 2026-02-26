#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef vector<vector<int>> Matrix;

Matrix add(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j]=A[i][j]+B[i][j];
    return C;
}

Matrix multiply(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n, 0));
    if (n==1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int k=n/2;
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
           A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)),
           B21(k, vector<int>(k)), B22(k, vector<int>(k));
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }
    }
    Matrix C11=add(multiply(A11,B11,k), multiply(A12,B21,k), k);
    Matrix C12=add(multiply(A11,B12,k), multiply(A12,B22,k), k);
    Matrix C21=add(multiply(A21,B11,k), multiply(A22,B21,k), k);
    Matrix C22=add(multiply(A21,B12,k), multiply(A22,B22,k), k);
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            C[i][j]=C11[i][j];
            C[i][j+k]=C12[i][j];
            C[i+k][j]=C21[i][j];
            C[i+k][j+k]=C22[i][j];
        }
    }
    return C;
}

int main() {
    vector<vector<double>> timings(10, vector<double>(10));
    vector<long long> testValues={2, 4, 8, 16, 32, 64};  
    cout << "Matrix Multiplication (Divide and Conquer) - Time Analysis\n";
    for (long long i=0; i<testValues.size(); i++) {
        long long n=testValues[i];
        Matrix A(n, vector<int>(n));
        Matrix B(n, vector<int>(n));
        srand(time(0)+i);
        for (long long row=0; row<n; row++) {
            for (long long col=0; col<n; col++) {
                A[row][col] = rand()%10;
                B[row][col] = rand()%10;
            }
        }
        double timeTaken=0;
        for (long long iter=0; iter<10; iter++) {
            auto start=chrono::high_resolution_clock::now();
            Matrix C = multiply(A, B, n);
            auto end=chrono::high_resolution_clock::now();
            chrono::duration<double, micro> duration=end-start;
            timings[i][iter]=duration.count();
            timeTaken+=duration.count();
        }
        double avgTime=timeTaken/10.0;
        cout << avgTime << ",";
    }
    cout << endl;
}