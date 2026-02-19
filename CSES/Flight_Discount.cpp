#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main() {
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	vector<vector<int>> dist(n + 1, vector<int> (2, 1e17));
	dist[1][0] = dist[1][1] = 0;
	multiset<vector<int>> ms;
	ms.insert({0, 0, 1});
	while(ms.size()) {
		int time = (*ms.begin())[0];
		int type = (*ms.begin())[1];
		int node = (*ms.begin())[2];
		if((time > dist[node][type])) {
			ms.erase(ms.begin());
			continue;	
		}
		ms.erase(ms.begin());
		for(auto [ch, cost] : adj[node]) {
			if(type == 0) {
				if(dist[node][0] + cost < dist[ch][0]) {
					dist[ch][0] = dist[node][0] + cost;
					ms.insert({dist[ch][0], 0, ch});
				}
				if(dist[node][0] + (cost / 2) < dist[ch][1]) {
					dist[ch][1] = dist[node][0] + (cost / 2);
					ms.insert({dist[ch][1], 1, ch});
				}
			}else {
				if(dist[node][1] + cost < dist[ch][1]) {
					dist[ch][1] = dist[node][1] + cost;
					ms.insert({dist[ch][1], 1, ch});
				}
			}
		}
	}
	cout << dist[n][1] << endl;
}