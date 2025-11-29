#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, y, r;
        cin >> n >> y >> r;

        int yellow_susp = y / 2;
        int red_susp = r;

        int ans = min(n, yellow_susp + red_susp);
        cout << ans << endl;
    }

    return 0;
}
