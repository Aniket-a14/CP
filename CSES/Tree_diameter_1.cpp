#include <bits/stdc++.h>
using namespace std;

int deep, maxi;

void find(vector<vector<int>>& adj, int node, int parent, int level) {
    if (level > maxi) {
        maxi = level;
        deep = node;
    }

    for (auto neigh : adj[node]) {
        if (neigh != parent) {
            find(adj, neigh, node, level + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find(adj, 1, 0, 0);
    find(adj, deep, 0, 0);

    cout << maxi << endl;
}
