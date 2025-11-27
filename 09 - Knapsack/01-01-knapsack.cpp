#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<long long> dp(W+1, 0);

    for (int i = 0; i < n; i++) {
        for (int cap = W; cap >= weight[i]; cap--) {
            dp[cap] = max(dp[cap], value[i] + dp[cap - weight[i]]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}