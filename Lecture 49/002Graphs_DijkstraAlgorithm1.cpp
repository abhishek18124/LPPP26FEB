/*

**************************************
Implementation of Dijkstra's Algorithm
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
#include<set>

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

	vector<int> dist(n, INF); // distance array
	dist[src] = 0;

	set<pii> minHeap;
	for (int i = 0; i < n; i++) {
		minHeap.insert({dist[i], i});
	}

	vector<bool> exp(n, false);

	// time : VlogV + ElogV or O(V+E)logV)
	// space: V due to minHeap + V due to exp[] + V due to dist ~ O(V)

	while (!minHeap.empty()) {

		// pii p = *minHeap.begin();
		// int du = p.first;
		// int u = p.second;

		auto [du, u] = *minHeap.begin(); // const
		minHeap.erase(minHeap.begin());  // logV or logn

		for (auto [v, w] : adj[u]) {
			if (!exp[v] and dist[v] > du + w) {
				minHeap.erase({dist[v], v}); // logV or logn
				dist[v] = du + w; // const
				minHeap.insert({dist[v], v}); // logV or logn
			}
		}

		exp[u] = true; // const

	}

	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}

	return 0;

}