#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long knapsack(long long W,vector<long long>& val,vector<long long>& wt) {
        vector<long long> dp(W + 1, 0);

        for (size_t i = 0; i < val.size(); i++) {
            for (int j = W; j >= wt[i]; j--) {
                dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, W;
    cin >> n >> W;

    vector<long long> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    Solution s;
    cout << s.knapsack(W, val, wt) << "\n";
}
