#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B; // Input the two strings

    int n = A.size();
    int m = B.size();

    // dp[i][j] stores the length of LCS between 
    // first i characters of A and first j characters of B
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table using standard LCS recurrence
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // If characters match, extend the LCS ending at previous indices
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // If characters don't match, take the maximum LCS by excluding
            // either the current character of A or B
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS string by backtracking from dp[n][m]
    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            // If characters match, include it in LCS and move diagonally
            lcs += A[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            // Move up if dp[i-1][j] is larger
            i--;
        }
        else {
            // Move left if dp[i][j-1] is larger or equal
            j--;
        }
    }

    // Reverse the string since we collected it backwards
    reverse(lcs.begin(), lcs.end());

    cout << lcs << endl; // Output the LCS
    return 0;
}
