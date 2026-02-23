#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, m; 
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i = 0; i < m; i++){
        int a, b, c; 
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<bool> visited(n+1,false);
    vector<int> mincost(n+1, LLONG_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    mincost[1] = 0;

    int ans = 0;

    while(!pq.empty()){
        auto [cost,node] = pq.top();
        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;
        ans += cost;

        for(auto [ch,wt] : adj[node]){
            if(!visited[ch] && wt < mincost[ch]){
                mincost[ch] = wt;
                pq.push({wt,ch});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << ans << endl;
}