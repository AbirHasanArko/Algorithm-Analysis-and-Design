#include <bits/stdc++.h>
using namespace std;

// Recursive function to print all subsets
void printSubsets(int i, int sum, vector<int> &nums, vector<vector<bool>> &dp, vector<int> &current) {
    // Base case: if remaining sum is 0, print current subset
    if (sum == 0) {
        cout << "{ ";
        for (int x : current) cout << x << " ";
        cout << "}" << endl;
        return;
    }

    // If no elements left, return
    if (i == 0) return;

    // Case 1: Exclude current element
    if (dp[i-1][sum])
        printSubsets(i-1, sum, nums, dp, current);

    // Case 2: Include current element (if possible)
    if (sum >= nums[i-1] && dp[i-1][sum - nums[i-1]]) {
        current.push_back(nums[i-1]);
        printSubsets(i-1, sum - nums[i-1], nums, dp, current);
        current.pop_back(); // backtrack
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target sum: ";
    cin >> target;

    // 1D DP for counting subsets (efficient)
    vector<long long> dp_count(target + 1, 0);
    dp_count[0] = 1; // sum 0 is always possible

    for (int num : nums) {
        for (int sum = target; sum >= num; sum--) {
            dp_count[sum] += dp_count[sum - num];
        }
    }

    if (dp_count[target] > 0)
        cout << "There exists at least one subset with sum " << target << "\n";
    else
        cout << "No subset exists with sum " << target << "\n";

    cout << "Total subsets with sum " << target << ": " << dp_count[target] << "\n";

    // Prepare DP table for backtracking (2D DP)
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= target; sum++) {
            if (sum >= nums[i-1])
                dp[i][sum] = dp[i-1][sum] || dp[i-1][sum - nums[i-1]];
            else
                dp[i][sum] = dp[i-1][sum];
        }
    }

    // Print all subsets (only for small n)
    if (n <= 20) {
        cout << "Subsets with sum " << target << ":\n";
        vector<int> current;
        printSubsets(n, target, nums, dp, current);
    }

    return 0;
}
