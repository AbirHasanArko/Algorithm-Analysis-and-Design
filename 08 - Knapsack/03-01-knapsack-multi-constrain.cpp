#include <bits/stdc++.h>
using namespace std;

/*
    Multiple-Constraint (2D) 0/1 Knapsack
    -------------------------------------
    Each item has:
      - weight[i]
      - volume[i]
      - value[i]
    We cannot exceed:
      - total weight ≤ W
      - total volume ≤ V

    dp[w][v] = best value with max weight w and max volume v
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W, V;
    cin >> n >> W >> V;

    vector<int> weight(n), volume(n), value(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> volume[i] >> value[i];

    vector<vector<long long>> dp(W + 1, vector<long long>(V + 1, 0));

    // 0/1 knapsack → iterate backwards
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            for (int v = V; v >= volume[i]; v--) {
                dp[w][v] = max(dp[w][v],
                               value[i] + dp[w - weight[i]][v - volume[i]]);
            }
        }
    }

    cout << dp[W][V] << "\n";
    return 0;
}
