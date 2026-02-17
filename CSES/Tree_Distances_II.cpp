#include<bits/stdc++.h>
using namespace std;

vector<int> subordinates;
vector<int> ans;

int countSubordinates(vector<vector<int>>& adj, int node, int parent){
    if(adj[node].size()== 0) return 0;

    for(auto child : adj[node]){
        subordinates[node] += 1 + countSubordinates(adj, child, node);
    }
    return subordinates[node];
}

void dfs(int node, int parent){
    for(auto child : adj[node]){
        if(child == parent) continue;
        ans[child] += (1 + subordinates[node] - subordinates[child] - ans[child]);
        dfs(child, node);
    }
}



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

    subordinates.resize(n+1, 0);
    ans.resize(n+1, 0);

    countSubordinates(adj, 1, -1);
    dfs(1, -1);

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
}