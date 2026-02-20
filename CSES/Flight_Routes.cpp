#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    int n,m,k; cin >> n >> m >> k;

    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});

    vector<vector<int>> dist(n + 1);
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int node = top.second;

        if(dist[node].size() == k) continue;
        dist[node].push_back(d);

        for(auto ch : adj[node]){
            int nextNode = ch.first;
            int nextDist = ch.second;

            if(dist[nextNode].size() < k){
                pq.push({d + nextDist, nextNode});
            }
        }
    }

    for(int i = 0; i < k; i++){
        cout << dist[n][i] << " \n"[i == k - 1];
    }

}
