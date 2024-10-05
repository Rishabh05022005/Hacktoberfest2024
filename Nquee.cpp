#include <iostream>
#include <vector>
using namespace std;

// Function to print the chessboard
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) return false;
    }

    return true;
}

// Backtracking function to solve the N-Queens problem
bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    // If all queens are placed
    if (row == N) {
        printBoard(board);  // Print one of the possible solutions
        return true;
    }

    bool res = false;
    // Try placing the queen in all columns for the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recursively place the rest of the queens
            res = solveNQueens(board, row + 1, N) || res;

            // Backtrack: Remove the queen if no solution is found
            board[row][col] = 0;
        }
    }

    return res;
}

int main() {
    int N;
    cout << "Enter the size of the board (N): ";
    cin >> N;

    // Initialize the chessboard
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Solve the N-Queens problem
    if (!solveNQueens(board, 0, N)) {
        cout << "No solution exists for N = " << N << endl;
    }

    return 0;
}
