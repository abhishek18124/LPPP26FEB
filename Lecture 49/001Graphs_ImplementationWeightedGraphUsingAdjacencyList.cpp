/*

*****************************************************
Implementation of Weighted Graph using Adjacency List
*****************************************************

input

5 6
0 1 7
0 2 1
1 3 2
2 3 9
2 4 6
3 4 5

*/

#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

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

	// print the adjacency list
	for (int i = 0; i < n; i++) {
		cout << "neighbors(" << i << ") : ";
		for (auto [v, w] : adj[i]) {
			cout << "(" << v << ", " << w << ") ";
		}
		cout << '\n';
	}

	cout << "\n";

	for (int i = 0; i < n; i++) {
		cout << "neighbors(" << i << ") : ";
		for (pii p : adj[i]) {
			int v = p.first;
			int w = p.second;
			cout << "(" << v << ", " << w << ")";
		}
		cout << "\n";
	}

	return 0;

}