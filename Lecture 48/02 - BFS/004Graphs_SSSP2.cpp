/*

***********************************
SSSP for Unweighted Graph using BFS
***********************************

input
9 12
0  1
0  2
1  3
1  4
2  4
2  5
3  6
4  6
4  7
5  7
6  8
7  8

output
0 1 1 2 2 2 3 3 4

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> dis; // distance array
vector<vector<int>> adj;

const int INF = 1e9 + 7;

void bfs(int src) { // src = source node

	queue<int> q;

	// initialize the source node
	dis[src] = 0;
	q.push(src);

	while (!q.empty()) {

		int u = q.front(); // u = current node
		q.pop();

		// explore all the neighbors of the current node
		for (int v : adj[u]) { // v = neighbor of u
			if (dis[v] == INF) { // if dis[v] is still INF, it means we haven't visited it yet.
				dis[v] = dis[u] + 1; // distance to neighbor from src is the distance of current node from src + 1
				q.push(v);
			}
		}
	}

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	dis.assign(n, INF);
	adj.assign(n, {});

	// read the graph

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment out this line if the graph is directed
	}

	bfs(0); // find shortest paths from node 0

	for (int i = 0; i < n; i++) {
		cout << dis[i] << " ";

	}

	return 0;
}