#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long x;
        cin >> x;

        bool possible = false;

        if (n == 1) {
            possible = (a[0] == x);
        } else {
            for (int i = 0; i + 1 < n; i++) {
                if (min(a[i], a[i+1]) <= x && x <= max(a[i], a[i+1])) {
                    possible = true;
                    break;
                }
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
