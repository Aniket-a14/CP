#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // separate evens and odds (descending)
        vector<ll> ev, od;
        for (ll x : a) {
            if (x % 2 == 0) ev.push_back(x);
            else od.push_back(x);
        }
        sort(ev.begin(), ev.end(), greater<ll>());
        sort(od.begin(), od.end(), greater<ll>());

        int E = (int)ev.size();
        int O = (int)od.size();

        // prefix sums of evens for quick sum of top r evens
        vector<ll> preE(E+1, 0);
        for (int i = 0; i < E; ++i) preE[i+1] = preE[i] + ev[i];

        // If there is no odd, every answer is 0 (you can never end with an odd-sum suffix)
        if (O == 0) {
            for (int k = 1; k <= n; ++k) {
                cout << 0 << (k==n?'\n':' ');
            }
            continue;
        }

        ll bestOdd = od[0];

        auto feasible = [&](int k, int r)->bool {
            // r = number of evens we plan to keep in final suffix (0 <= r <= E, r <= k-1)
            if (r < 0 || r > E) return false;
            if (r > k-1) return false;
            int m = k - 1 - r; // number of wasted picks (must have even sum)
            // remaining counts after reserving final coins:
            int rem_e = E - r;
            int rem_o = O - 1; // we reserved one odd for the final suffix
            int rem_total = rem_e + rem_o;
            if (m > rem_total) return false;

            // We need to choose exactly m coins among remaining such that number of chosen odds is even.
            // That means exists x in [0..m] with x <= rem_o and (m-x) <= rem_e and x even.
            int low = max(0, m - rem_e);
            int high = min(rem_o, m);
            if (low > high) return false;
            // check if [low, high] contains an even integer
            if ((low % 2) == 0) return true;
            if (low + 1 <= high) return true;
            return false;
        };

        // For each k, binary search largest feasible r in [0, min(E, k-1)]
        vector<ll> ans(n+1, 0);
        for (int k = 1; k <= n; ++k) {
            int rlo = 0, rhi = min(E, k-1);
            int best_r = -1;
            while (rlo <= rhi) {
                int mid = (rlo + rhi) >> 1;
                if (feasible(k, mid)) {
                    best_r = mid;
                    rlo = mid + 1; // try larger r (we want max r)
                } else {
                    rhi = mid - 1;
                }
            }
            if (best_r == -1) ans[k] = 0;
            else ans[k] = bestOdd + preE[best_r];
        }

        for (int k = 1; k <= n; ++k) {
            cout << ans[k] << (k==n?'\n':' ');
        }
    }
    return 0;
}
