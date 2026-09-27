/*

https://codeforces.com/problemset/problem/20/C

input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

output
1 4 3 5

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;

const ll INF = 1e18;

vector<ll> dist; // distance array
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
		u--; v--; // convert 1-based input to 0-based indexing
		int w; cin >> w; // weight of the edge
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // comment out this line if the graph is directed
	}

	int src = 0; // assume node 0 to be the source vertex

	dist.assign(n, INF);
	dist[src] = 0;

	par.assign(n, -1); // initialize all parents to -1 (src parent naturally stays -1)

	priority_queue<pli, vector<pli>, greater<pli>> minHeap;
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
		cout << -1;
	} else {
		for (int i = 0; i < (int)path.size(); i++) {
			cout << path[i] + 1 << " ";
		}
	}

	return 0;

}