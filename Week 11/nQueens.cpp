#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col >= n)
        return true;
    
    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            
            if (solveNQueens(board, col + 1, n))
                return true;
            
            board[row][col] = 0;
        }
    }
    
    return false;
}

void printBoard(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    if (solveNQueens(board, 0, n)) {
        cout << "Solution exists for " << n << " Queens:\n";
        printBoard(board, n);
    } else {
        cout << "No solution exists for " << n << " Queens\n";
    }
    
    return 0;
}
