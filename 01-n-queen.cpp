#include <bits/stdc++.h>

using namespace std;

int N;
int ways = 0;

// for fixed queen
int fixedRow;
int fixedCol;

void printBoard(vector<vector<int>> &board)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) return false;
    }
    return true;
}

bool solveNQueen(vector<vector<int>> &board, int row)
{
    if (row == N) {
        ways++;
        printBoard(board);
        return true;
    }

    if (row == fixedRow) {
        return solveNQueen(board, row + 1);
    }

    bool found = false;
    for (int col = 0; col < N; col++) {
        if (col == fixedCol) continue;;

        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            found = solveNQueen(board, row + 1) || found;
            board[row][col] = 0;
        }
    }
    return found;
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> N;

    cout << "Enter position of fixed queen (row and column, 0-indexed, (-1,-1) if none): ";
    cin >> fixedRow >> fixedCol;

    vector<vector<int>> board(N, vector<int>(N, 0));
    if (fixedRow >= 0 && fixedCol >= 0) {
        board[fixedRow][fixedCol] = 1;
    }

    if (!solveNQueen(board, 0)) {
        cout << "No solution exists for " << N << " queens.\n";
    } else {
        cout << ways << " solutions are shown above.\n";
    }
    
    return 0;
}