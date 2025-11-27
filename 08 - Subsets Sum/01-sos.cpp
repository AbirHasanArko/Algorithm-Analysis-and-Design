#include <bits/stdc++.h>
using namespace std;

// Function to print a vector
void printSubset(const vector<int> &subset) {
    cout << "{ ";
    for (int num : subset) cout << num << " ";
    cout << "}" << endl;
}

// Backtracking function to find all subsets with given sum
void sumOfSubsets(int index, vector<int> &nums, vector<int> &current, int target, int &count) {
    // Base case: if target is 0, we found a valid subset
    if (target == 0) {
        printSubset(current);
        count++;
        return;
    }

    // If no more elements or target becomes negative
    if (index == nums.size() || target < 0)
        return;

    // Include nums[index]
    current.push_back(nums[index]);
    sumOfSubsets(index + 1, nums, current, target - nums[index], count);

    // Exclude nums[index] (backtrack)
    current.pop_back();
    sumOfSubsets(index + 1, nums, current, target, count);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;

    vector<int> currentSubset;
    int totalCount = 0;

    cout << "All subsets with sum " << target << ":\n";
    sumOfSubsets(0, nums, currentSubset, target, totalCount);

    cout << "Total subsets found: " << totalCount << endl;
    return 0;
}
