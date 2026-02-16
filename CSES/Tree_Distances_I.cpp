#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto bfs = [&](int start){
        vector<int> dist(n+1, -1);
        queue<int> q;
        q.push(start);
        dist[start]=0;

        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                if(dist[v]==-1){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    auto d1 = bfs(1);
    int A = 1;
    for(int i=1;i<=n;i++){
        if(d1[i] > d1[A]) A = i;
    }

    auto distA = bfs(A);
    int B = A;
    for(int i=1;i<=n;i++){
        if(distA[i] > distA[B]) B = i;
    }

    auto distB = bfs(B);

    for(int i=1;i<=n;i++){
        cout << max(distA[i], distB[i]) << " ";
    }
}
