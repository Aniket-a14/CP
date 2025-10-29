//D. Yet another Array Problem
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<unsigned long long> arr(n);
        for (auto &x : arr) cin >> x;

        unsigned long long ans = -1;
        for (unsigned long long x = 2; x <= 1000; x++) {
            for (auto v : arr) {
                if (__gcd(v, x) == 1) {
                    ans = x;
                    break;
                }
            }
            if (ans != (unsigned long long)(-1)) break;
        }

        cout << ans << "\n";
    }
}
