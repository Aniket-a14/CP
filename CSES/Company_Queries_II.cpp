#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> level;

void dfs(int node)
{
    for (auto ch : adj[node])
    {
        level[ch] = 1 + level[node];
        dfs(ch);
    }
}

int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;

    adj.resize(n + 1);
    level.resize(n+1,0);
    vector<vector<int>> binaryLifting(n + 1, vector<int>(31, -1));

    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;

        binaryLifting[i][0] = a;
        adj[a].push_back(i);
    }

    dfs(1);
    for (int j = 1; j <= 30; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int first = binaryLifting[i][j - 1];
            if (first != -1)
                binaryLifting[i][j] = binaryLifting[first][j - 1];
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int diff = abs(level[a] - level[b]);
        int start = 0;
        int end = min(level[a], level[b]);
        int ans = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            int parent_1 = (level[a] <= level[b] ? mid : mid + diff);
            int parent_2 = (level[b] <= level[a] ? mid : mid + diff);

            int p = a;
            for (int j = 30; j >= 0; j--)
            {
                if (parent_1 & (1 << j))
                {
                    p = binaryLifting[p][j];
                }
                if (p == -1)
                {
                    break;
                }
            }
            int p2 = b;
            for (int j = 30; j >= 0; j--)
            {
                if (parent_2 & (1 << j))
                {
                    p2 = binaryLifting[p2][j];
                }
                if (p2 == -1)
                {
                    break;
                }
            }
            
            if(p==p2){
                ans = p;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        cout<<ans<<endl;
    }
}