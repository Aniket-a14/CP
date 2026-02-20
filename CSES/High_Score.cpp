#include <bits/stdc++.h>
using namespace std;

#define int long long int

void dfs(int node, vector<int> &connection, vector<vector<int>> &rev) {
	for(auto ch : rev[node]) {
		if(!connection[ch]) {
			connection[ch] = 1;
			dfs(ch, connection, rev);
		}
	}
}

int32_t main() {
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>> edges(m, vector<int> (3));
	vector<vector<int>> rev(n + 1);
	for(int i = 0; i < m; i++) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
		edges[i][2] = -edges[i][2]; 
		rev[edges[i][1]].push_back(edges[i][0]); 
	}

	vector<int> dist(n + 1, 1e16);
	dist[1] = 0;
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m; j++) {
			int a = edges[j][0];
			int b = edges[j][1];
			int cost = edges[j][2];
			if(dist[a] == 1e16) continue;
			dist[b] = min(dist[b], dist[a] + cost);
		}
	}

	bool check = true;
	vector<int> connection(n + 1, 0);
	connection[n] = 1;
	dfs(n, connection, rev);
	for(int j = 0; j < m; j++) {
		int a = edges[j][0];
		int b = edges[j][1];
		int cost = edges[j][2];
		if(dist[a] == 1e16) continue;
		if((dist[b] > dist[a] + cost) && connection[b]) {
			check = false;
			break;
		}
	}
	if(check) {
		cout << -dist[n] << endl;
		return 0;
	}
	cout << -1 << endl;
}