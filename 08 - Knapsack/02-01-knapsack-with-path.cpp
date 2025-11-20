#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> w(n+1), v(n+1);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    vector<vector<long long>> dp(n+1, vector<long long>(W+1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap <= W; cap++) {
            dp[i][cap] = dp[i-1][cap];   // skip
            if (cap >= w[i]) {
                dp[i][cap] = max(dp[i][cap], v[i] + dp[i-1][cap - w[i]]);
            }
        }
    }

    cout << "Max value: " << dp[n][W] << "\n";

    // Reconstruction
    int cap = W;
    vector<int> taken;
    for (int i = n; i > 0; i--) {
        if (dp[i][cap] == dp[i-1][cap]) {
            // item i not taken
            continue;
        } else {
            // item i taken
            taken.push_back(i);
            cap -= w[i];
        }
    }

    reverse(taken.begin(), taken.end());

    cout << "Items taken: ";
    for (int x : taken) cout << x << " ";
    cout << "\n";

    return 0;
}
