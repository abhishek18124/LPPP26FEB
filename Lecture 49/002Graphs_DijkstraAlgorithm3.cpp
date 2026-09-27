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

	vector<int> dist(n, INF); // distance array
	dist[src] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> minHeap;
	minHeap.push({dist[src], src});

	vector<int> exp(n, false);

	// time : O(V+E)logE) since E can ~ V^2 in worst case and logV^2 ~ 2logV we get back the same time complexity as before
	// space: E due to minHeap + V due to exp[] + V due to dist ~ O(V+E)

	while (!minHeap.empty()) {

		auto [du, u] = minHeap.top();
		minHeap.pop();

		/*

		***********************
		THE LAZY DELETION TRICK
		***********************

		Because we cannot randomly erase from a priority_queue, we might have pushed
		multiple distances for node 'u'. If this popped distance is strictly greater
		than the best distance we've found so far, it is stale so ignore it.

		*/

		if (du > dist[u]) continue;

		for (auto [v, w] : adj[u]) {
			if (!exp[v] and dist[v] > du + w) {
				dist[v] = du + w;
				minHeap.push({dist[v], v}); // blindly push the new better distance
			}
		}

		exp[u] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}

	return 0;

}