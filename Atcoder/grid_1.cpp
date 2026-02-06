#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int path(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0) return 0;
        if (grid[i][j] == '#') return 0;
        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] =
            (path(i-1, j, grid) + path(i, j-1, grid)) % MOD;
    }
};

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];

    Solution s;
    s.dp.assign(h, vector<int>(w, -1));

    cout << s.path(h-1, w-1, grid) << endl;
}
