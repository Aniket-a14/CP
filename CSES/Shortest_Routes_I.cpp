#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    const int INF = LLONG_MAX;
    vector<int> dist(n+1, INF);
    dist[1] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, 1});

    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();

        if(d > dist[node]) continue;

        for(auto [ch, cost] : adj[node]){
            if(dist[node] + cost < dist[ch]){
                dist[ch] = dist[node] + cost;
                pq.push({dist[ch], ch});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
}
