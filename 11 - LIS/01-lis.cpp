#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements in the array

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; // Input the array elements

    // dp[i] will store the length of the LIS ending at index i
    vector<int> dp(n, 1);  
    // parent[i] stores the index of the previous element in LIS ending at i
    vector<int> parent(n, -1);

    int maxLen = 1;   // Length of overall LIS
    int lastIdx = 0;  // Index of the last element of the LIS

    // Fill dp[] using the standard LIS DP approach
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Check if a[j] can be extended by a[i]
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;  // Update LIS length ending at i
                parent[i] = j;      // Remember previous index to reconstruct LIS
            }
        }

        // Update overall maximum LIS length and its last index
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIdx = i;
        }
    }

    // Reconstruct the LIS sequence using parent[]
    vector<int> lis;
    while (lastIdx != -1) {
        lis.push_back(a[lastIdx]);   // Add current element to LIS
        lastIdx = parent[lastIdx];   // Move to previous element in LIS
    }
    reverse(lis.begin(), lis.end()); // Reverse to get correct order

    // Print the LIS
    for (int x : lis) cout << x << " ";
    cout << endl;

    return 0;
}
