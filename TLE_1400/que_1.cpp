#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> l(m + 1), r(m + 1);
    vector<ll> d(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
    }

    vector<ll> op_count(m + 2, 0);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        op_count[x] += 1;
        op_count[y + 1] -= 1;
    }

    for (int i = 1; i <= m; i++)
    {
        op_count[i] += op_count[i - 1];
    }

    vector<ll> diff(n + 2, 0);
    for (int i = 1; i <= m; i++)
    {
        if (op_count[i] == 0)
            continue;
        diff[l[i]] += d[i] * op_count[i];
        diff[r[i] + 1] -= d[i] * op_count[i];
    }

    ll cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += diff[i];
        a[i] += cur;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}
