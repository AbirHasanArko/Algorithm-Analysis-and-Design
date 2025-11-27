#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B; // Input two strings to find the longest common substring

    int n = A.size();
    int m = B.size();

    // dp[i][j] will store the length of the longest common substring
    // ending at A[i-1] and B[j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLen = 0;   // To keep track of the length of the longest common substring found
    int endPos = 0;   // To store the ending index of the substring in string A

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // If characters match, extend the previous substring
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                // Update maxLen and endPos if this substring is the longest so far
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endPos = i - 1;  // store index of last character of substring in A
                }
            }
            else {
                dp[i][j] = 0; // No match, so substring length resets to 0
            }
        }
    }

    // Extract the longest common substring using endPos and maxLen
    string answer = A.substr(endPos - maxLen + 1, maxLen);
    cout << answer << endl; // Output the result

    return 0;
}
