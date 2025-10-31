//Cycle Sort(TLE)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        vector<long long> arr1(n), arr2(m);
        for (auto &x : arr1) cin >> x;
        for (auto &x : arr2) cin >> x;

        long long lcm = (n / __gcd(n, m)) * m;
        k = min(k, lcm);

        for (long long i = 0; i < k; i++) {
            int a = i % n;
            int b = i % m;
            if (arr1[a] > arr2[b])
                swap(arr1[a], arr2[b]);
        }

        for (int i = 0; i < n; i++)
            cout << arr1[i] << (i + 1 == n ? '\n' : ' ');
        for (int i = 0; i < m; i++)
            cout << arr2[i] << (i + 1 == m ? '\n' : ' ');
    }

    return 0;
}
