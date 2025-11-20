#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    // Order does not matter → coin loop outer
    for (int c : coins) {
        for (int sum = c; sum <= x; sum++) {
            dp[sum] = (dp[sum] + dp[sum - c]) % MOD;
        }
    }

    cout << dp[x] << "\n";
}
