#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
int count(vector<vector<int>>&adj, int node, int parent){
    if(adj[node].size()==0) return 0;

    for(auto neigh: adj[node]){
        ans[node] += 1 + count(adj,neigh,node);
    }

    return ans[node];
}

int main(){
    int n;cin>>n;
    ans.resize(n+1,0);
    vector<vector<int>> adj(n+1);

    for(int i=2;i<=n;i++){
        int a; cin>>a;

        // adj[i].push_back(a);
        adj[a].push_back(i);
    }

    count(adj,1,0);

    for(int i = 1; i<=n;i++){
        cout<< ans[i]<< " ";
    }
}