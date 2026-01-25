#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        int64 x;
        cin >> n >> x;

        vector<int64> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }

        int64 max_free = 0;
        for (int i = 0; i < n; i++) {
            max_free = max(max_free, (b[i] - 1) * a[i]);
        }

        if (max_free >= x) {
            cout << 0 << "\n";
            continue;
        }

        int64 best_gain = 0;
        for (int i = 0; i < n; i++) {
            best_gain = max(best_gain, b[i] * a[i] - c[i]);
        }

        if (best_gain <= 0) {
            cout << -1 << "\n";
            continue;
        }

        int64 lo = 1, hi = (x + best_gain - 1) / best_gain + 5;
        int64 ans = -1;

        while (lo <= hi) {
            int64 mid = (lo + hi) / 2;
            int64 reach = 0;

            for (int i = 0; i < n; i++) {
                int64 gain = b[i] * a[i] - c[i];
                if (gain > 0) {
                    reach = max(reach, (b[i] - 1) * a[i] + mid * gain);
                }
            }

            if (reach >= x) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
