/*

********************************************
Implementation of Graph using Adjacency List
********************************************

input

5 6
0 1
0 2
1 3
2 3
2 4
3 4

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; // n = number of nodes, m = number of edges
	cin >> n >> m;

	// vector<set<int>> adj(n); // adj[i] stores all the neighbors of node i
	vector<set<int, greater<int>>> adj(n);

	// read edges
	for (int i = 0; i < m; i++) {
		int u, v; // endpoints of the edge
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u); // comment out this line if the graph is directed
	}

	// print the adjacency list
	for (int i = 0; i < n; i++) {
		cout << "neighbors(" << i << ") : ";
		for (int v : adj[i]) {
			cout << v << " ";
		}
		cout << '\n';
	}

	return 0;
}