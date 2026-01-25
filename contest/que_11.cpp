//Table with Numbers
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, h, l;
        cin >> n >> h >> l;

        int A = 0, B = 0, C = 0;
        int m = min(h, l);

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x <= m) A++;
            else if(x <= h) B++;
            else if(x <= l) C++;
        }

        int answer = min({
            A + B,
            A + C,
            (A + B + C) / 2
        });

        cout << answer << "\n";
    }
    return 0;
}
