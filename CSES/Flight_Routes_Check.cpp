#include <bits/stdc++.h>
using namespace std;
 
void dfs(int start, const vector<vector<int>> &adj, vector<bool> &vis) {
    stack<int> st;
    st.push(start);
    vis[start] = true;
 
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        for (int nxt : adj[node]) {
            if (!vis[nxt]) {
                vis[nxt] = true;
                st.push(nxt);
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> adj(n + 1), adj_rev(n + 1);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
 
    vector<bool> vis(n + 1, false), vis_rev(n + 1, false);
 
    dfs(1, adj, vis);
    dfs(1, adj_rev, vis_rev);
 
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (!vis_rev[i]) {
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
    }
 
    cout << "YES\n";
    return 0;
}