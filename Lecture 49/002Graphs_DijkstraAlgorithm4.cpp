/*

**************************************
Implementation of Dijkstra's Algorithm
(With Lazy Deletion)
**************************************

input
5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output
0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9 + 7;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; // n = number of nodes, m = number of edges
	cin >> n >> m;

	vector<vector<pii>> adj(n); // adj[i] stores all the neighbors of node i

	// read edges

	for (int i = 0; i < m; i++) {
		int u, v; // endpoints of the edge
		cin >> u >> v;
		int w; cin >> w; // weight of the edge
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // comment out this line if the graph is directed
	}

	int src = 0; // assume node 0 to be the source vertex

	vector<int> dist(n, INF);
	dist[src] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> minHeap;
	minHeap.push({dist[src], src});

	while (!minHeap.empty()) {

		auto [du, u] = minHeap.top();
		minHeap.pop();

		// lazy deletion: ignore stale disttances
		if (du > dist[u]) continue;

		for (auto [v, w] : adj[u]) {
			if (dist[v] > du + w) {
				dist[v] = du + w;
				minHeap.push({dist[v], v});
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}

	return 0;

}