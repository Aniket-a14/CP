#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int day, vector<int> &swim, vector<int> &catch_bugs, vector<int> &homework, vector<vector<int>> &dp, int last)
    {
        if (day < 0)
            return 0;

        if (dp[day][last] != -1)
            return dp[day][last];

        int ans = INT_MIN;

        if (last != 0)
            ans = max(ans, swim[day] + solve(day - 1, swim, catch_bugs, homework, dp, 0));

        if (last != 1)
            ans = max(ans, catch_bugs[day] + solve(day - 1, swim, catch_bugs, homework, dp, 1));

        if (last != 2)
            ans = max(ans, homework[day] + solve(day - 1, swim, catch_bugs, homework, dp, 2));

        return dp[day][last] = ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> swim(n), catch_bugs(n), homework(n);
    for (int i = 0; i < n; i++)
        cin >> swim[i] >> catch_bugs[i] >> homework[i];

    vector<vector<int>> dp(n, vector<int>(4, -1));
    Solution s;
    cout << s.solve(n - 1, swim, catch_bugs, homework, dp, 3);
}