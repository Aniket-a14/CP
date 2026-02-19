#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    int n, m, q; cin>> n >> m >> q;

    vector<vector<int>> ans(n+1, vector<int>(n+1, LLONG_MAX));

    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        ans[u][v] = min(ans[u][v], w);
        ans[v][u] = min(ans[v][u], w);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(ans[i][k] != LLONG_MAX && ans[k][j] != LLONG_MAX){
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                }
            }
        }
    }

    for(int i = 0; i < q; i++){
        int u, v; cin >> u >> v;
        if(ans[u][v] == LLONG_MAX) cout << -1 << "\n";
        else cout << ans[u][v] << "\n";
    }
}