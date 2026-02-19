#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
bool visited[N];
int parent[N];

int start_node = -1, end_node = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;

    for (auto neigh : adj[node]) {
        if (neigh == par) continue;

        if (visited[neigh]) {
            start_node = neigh;
            end_node = node;
            return true;
        }

        if (!visited[neigh]) {
            if (dfs(neigh, node)) return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(start_node);

    for (int v = end_node; v != start_node; v = parent[v])
        cycle.push_back(v);

    cycle.push_back(start_node);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (auto v : cycle)
        cout << v << " ";
}
