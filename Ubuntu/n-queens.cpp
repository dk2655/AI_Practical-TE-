#include<bits/stdc++.h>
using namespace std;

int N;

// Function for printing the solution
void printSol(vector<vector<int>> board) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Optimized isSafe function to check if current row, left diagonal, or right diagonal contains any queen
bool isSafe(int row, int col, vector<bool>& rows, vector<bool>& left_digonals, vector<bool>& right_digonals) {
    if (rows[row] || left_digonals[row + col] || right_digonals[row - col + N - 1]) {
        return false;
    }
    return true;
}

// Recursive function to solve N-queen Problem
bool solve(vector<vector<int>>& board, int col, vector<bool>& rows, vector<bool>& left_digonals, vector<bool>& right_digonals) {
    // Base Case: If all Queens are placed
    if (col >= N) {
        return true;
    }
    // Consider this Column and move in all rows one by one
    for(int i = 0; i < N; i++) {
        if (isSafe(i, col, rows, left_digonals, right_digonals)) {
            rows[i] = true;
            left_digonals[i + col] = true;
            right_digonals[i - col + N - 1] = true;
            board[i][col] = 1; // Placing the Queen in board[i][col]
            // Recur to place rest of the queens
            if (solve(board, col + 1, rows, left_digonals, right_digonals)) {
                return true;
            }
            // Backtracking
            board[i][col] = 0; // Removing the Queen from board[i][col]
            rows[i] = false;
            left_digonals[i + col] = false;
            right_digonals[i - col + N - 1] = false;
        }
    }
    return false;
}

int main() {
    // Taking input from the user
    cout << "Enter the number of rows for the square Board : ";
    cin >> N;
    // Board of size N*N
    vector<vector<int>> board(N, vector<int>(N, 0));
    // Arrays to tell which rows and diagonals are occupied
    vector<bool> rows(N, false);
    vector<bool> left_digonals(2 * N - 1, false);
    vector<bool> right_digonals(2 * N - 1, false);
    bool ans = solve(board, 0, rows, left_digonals, right_digonals);
    if (ans) {
        // Printing the solution Board
        printSol(board);
    } else {
        cout << "Solution Does not Exist\n";
    }
}
