#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n + 1);
    vector<int> in(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        in[b]++;  
    }

    vector<int> dist(n + 1, INT_MIN);
    vector<int> par(n + 1, -1);

    dist[1] = 0;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    int processed = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        processed++;

        for (int ch : edges[node]) {
            if (dist[node] != INT_MIN) {
                if (dist[node] + 1 > dist[ch]) {
                    dist[ch] = dist[node] + 1;
                    par[ch] = node;
                }
            }

            in[ch]--;
            if (in[ch] == 0) {
                q.push(ch);
            }
        }
    }

    if (processed != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    if (dist[n] == INT_MIN) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dist[n] + 1 << "\n";

    vector<int> path;
    int cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }

    reverse(path.begin(), path.end());

    for (int node : path) {
        cout << node << " ";
    }

    return 0;
}