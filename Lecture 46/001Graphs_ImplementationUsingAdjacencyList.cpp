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

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; // n = number of nodes, m = number of edges
	cin >> n >> m;

	vector<vector<int>> adj(n); // adj[i] stores all the neighbors of node i

	// read edges
	for (int i = 0; i < m; i++) {
		int u, v; // endpoints of the edge
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment out this line if the graph is directed
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