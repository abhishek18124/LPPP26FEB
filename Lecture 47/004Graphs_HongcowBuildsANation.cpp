/*

https://codeforces.com/problemset/problem/744/A

input
4 1 2
1 3
1 2

output
2

input
3 3 1
2
1 2
1 3
2 3

output
0

*/

#include<iostream>
#include<vector>
#include<numeric> // required for accumulate()
#include<algorithm> // required for max_element()

using namespace std;

vector<bool> vis; // keeps track of visited nodes
vector<vector<int>> adj; // adjacency list

int dfs(int u) { // u = current node

	// 1. mark the current node as visited
	vis[u] = true;

	// 2. process the current node (count this node as 1)
	int cnt = 1;

	// 3. explore all the neighbors of the current node
	for (int v : adj[u]) { // v = neighbor of u
		if (!vis[v]) { // if the neighbor hasn't been visited yet
			cnt += dfs(v); // recursively visit it and add its component sz
		}
	}

	return cnt; // return the total sz of this component

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> c(k);
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		c[i]--; // convert 1-based input to 0-based indexing
	}

	vis.assign(n, false);
	adj.assign(n, {});

	// read the graph

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--; // convert 1-based input to 0-based indexing
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// sz[i] will store the size of the component containing capital c[i]
	vector<int> sz(k, 0);
	for (int i = 0; i < k; i++) {
		sz[i] = dfs(c[i]);
	}

	// find the number of "free" nodes (nodes not connected to any capital)
	int free = n - accumulate(sz.begin(), sz.end(), 0);

	// find the index of the largest component
	int maxIdx = max_element(sz.begin(), sz.end()) - sz.begin();

	// attach all free nodes to the largest component to maximize possible edges
	sz[maxIdx] += free;

	int maxPossibleEdges = 0;
	for (int i = 0; i < k; i++) {
		maxPossibleEdges += sz[i] * (sz[i] - 1) / 2;
	}

	cout << maxPossibleEdges - m;

	return 0;
}