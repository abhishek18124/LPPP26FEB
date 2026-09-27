/*

********************************************
Implementation of Dijkstra's Algorithm
(With Lazy Deletion and Path Reconstruction)
********************************************

input
5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9 + 7;

vector<int> dist; // distance array
vector<int> par; // parent array to reconstruct paths
vector<vector<pii>> adj;

// function to reconstruct the path after Dijkstra has been run
vector<int> getPath(int dst) { // dst = destination node
	// if the destination is unreachable, return an empty path
	if (dist[dst] == INF) {
		return {};
	}

	vector<int> path;
	for (int cur = dst; cur != -1; cur = par[cur]) {
		path.push_back(cur);
	}

	reverse(path.begin(), path.end());

	return path;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; // n = number of nodes, m = number of edges
	cin >> n >> m;

	adj.assign(n, {}); // adj[i] stores all the neighbors of node i

	// read edges

	for (int i = 0; i < m; i++) {
		int u, v; // endpoints of the edge
		cin >> u >> v;
		int w; cin >> w; // weight of the edge
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // comment out this line if the graph is directed
	}

	int src = 0; // assume node 0 to be the source vertex

	dist.assign(n, INF);
	dist[src] = 0;

	par.assign(n, -1); // initialize all parents to -1 (src parent naturally stays -1)

	priority_queue<pii, vector<pii>, greater<pii>> minHeap;
	minHeap.push({dist[src], src});

	while (!minHeap.empty()) {

		auto [du, u] = minHeap.top();
		minHeap.pop();

		// lazy deletion: ignore stale distances
		if (du > dist[u]) continue;

		for (auto [v, w] : adj[u]) {
			if (dist[v] > du + w) {
				dist[v] = du + w;
				minHeap.push({dist[v], v});
				par[v] = u;
			}
		}

	}

	int dst = n - 1;

	vector<int> path = getPath(dst);

	if (path.empty()) {
		cout << "IMPOSSIBLE";
	} else {
		for (int i = 0; i < (int)path.size(); i++) {
			cout << path[i] << " ";
		}
	}

	return 0;

}