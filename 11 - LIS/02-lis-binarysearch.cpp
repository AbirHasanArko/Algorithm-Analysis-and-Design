#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> lis;                // stores the values
    vector<int> lisIndex;           // lisIndex[k] = index in a[] where LIS of length k ends
    vector<int> parent(n, -1);      // to reconstruct

    for (int i = 0; i < n; i++) {
        int x = a[i];
        auto it = lower_bound(lis.begin(), lis.end(), x);
        int pos = it - lis.begin();

        if (it == lis.end()) {
            lis.push_back(x);
            lisIndex.push_back(i);
        } else {
            *it = x;
            lisIndex[pos] = i;
        }

        if (pos > 0)
            parent[i] = lisIndex[pos - 1];
    }

    // Reconstruct LIS
    vector<int> result;
    int idx = lisIndex.back();
    while (idx != -1) {
        result.push_back(a[idx]);
        idx = parent[idx];
    }
    reverse(result.begin(), result.end());

    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
