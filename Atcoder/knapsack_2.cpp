#include <bits/stdc++.h>
using namespace std;

#define int long long int

vector<vector<int>> dp;

int knapsack(vector<int> &weight, vector<int> &val, int idx, int value) {
    if(value == 0) return 0;
    if(idx == val.size()) return 1e11;
    if(dp[idx][value] != -1) return dp[idx][value]; 
    int pick = 1e11, notPick = 0;
    if(val[idx] <= value) {
        pick = weight[idx] + knapsack(weight, val, idx + 1, value - val[idx]);
    }
    notPick = knapsack(weight, val, idx + 1, value);

    return dp[idx][value] = min(pick, notPick);
}

int32_t main() {
    int n; cin >> n;
    int w; cin >> w;;
    vector<int> weight(n), val(n);
    for(int i = 0; i < n; i++) cin >> weight[i] >> val[i];
    dp.resize(n, vector<int> (100001, -1));
    
    for(int value = 100000; value >= 0; value--) {
        int minWeight = knapsack(weight, val, 0, value);
        if(minWeight <= w) {
            cout << value << endl;
            return 0;
        }
    }
}