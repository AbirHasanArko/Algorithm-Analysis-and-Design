#include <bits/stdc++.h>

using namespace std;

int N;
int ways = 0;

// for fixed queen
int fixedRow;
int fixedCol;

// Function to print the board configuration
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

// Check if placing a queen at (row, col) is safe
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    // Check same column above
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) return false;
    }
    return true;
}

// Solve N-Queens using backtracking
bool solveNQueen(vector<vector<int>> &board, int row)
{
    // If all queens placed, we found a solution
    if (row == N) {
        ways++;
        cout << "Placement " << ways << ":\n";
        printBoard(board);
        return true;
    }

    // Skip this row if it already contains a fixed queen
    if (row == fixedRow) {
        return solveNQueen(board, row + 1);
    }

    bool found = false;

    // Try placing queen in each column
    for (int col = 0; col < N; col++) {
        // Skip fixed queen column
        if (col == fixedCol) continue;;

        // Check if safe
        if (isSafe(board, row, col)) {
            board[row][col] = 1;    // Place queen
            found = solveNQueen(board, row + 1) || found;
            board[row][col] = 0;    // Backtrack
        }
    }
    return found;
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> N;

    // Input fixed queen position
    cout << "Enter position of fixed queen (row and column, 0-indexed, (-1,-1) if none): ";
    cin >> fixedRow >> fixedCol;

    // Create NxN board initialized with 0
    vector<vector<int>> board(N, vector<int>(N, 0));

    // If fixed queen exists, place her on board
    if (fixedRow >= 0 && fixedCol >= 0) {
        board[fixedRow][fixedCol] = 1;
    }

    // Run solver
    if (!solveNQueen(board, 0)) {
        cout << "No solution exists for " << N << " queens.\n";
    } else {
        cout << ways << " solutions are shown above.\n";
    }
    
    return 0;
}

/*
Test Case 1:

Input:
4
-1 -1

Output:
Enter number of queens: 4
Enter position of fixed queen (row and column, 0-indexed, (-1,-1) if none): -1 -1
Placement 1:
. Q . . 
. . . Q 
Q . . . 
. . Q . 

Placement 2:
. . Q . 
Q . . . 
. . . Q 
. Q . . 

2 solutions are shown above.
*/

/*
Test Case 2:

Input:
6
3 3

Output:
Enter number of queens: 6
Enter position of fixed queen (row and column, 0-indexed, (-1,-1) if none): 3 3
Placement 1:
Q . . . . . 
. . Q . . . 
. . . . . Q 
. . . Q . . 
. Q . . . . 
. . . . Q .

Placement 2:
Q . . . . .
. . . . Q .
. Q . . . .
. . . Q . .
. . . . . Q
. . Q . . .

Placement 3:
. . . . . Q
. Q . . . .
. . . . Q . 
. . . Q . .
Q . . . . .
. . Q . . .

3 solutions are shown above. 
*/
