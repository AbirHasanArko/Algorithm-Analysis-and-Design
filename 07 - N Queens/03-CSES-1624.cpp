// https://cses.fi/problemset/task/1624
// Chessboard and Queens
/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

Example
Input:

........
........
..*.....
........
........
.....**.
...*....
........
Output:

65
*/

#include <bits/stdc++.h>
using namespace std;

char board[8][8];
bool col[8], diag1[15], diag2[15];
int ways = 0;

void solve(int row) {
    if (row == 8) {
        ways++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (board[row][c] == '*') continue;
        if (col[c] || diag1[row + c] || diag2[row - c + 7]) continue;

        col[c] = diag1[row + c] = diag2[row - c + 7] = true;
        solve(row + 1);
        col[c] = diag1[row + c] = diag2[row - c + 7] = false;
    }
}

int main()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    solve(0);

    cout << ways << endl;
    
    return 0;
}