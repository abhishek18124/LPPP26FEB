/*

https://cses.fi/ckvo8q5wh/task/1667

input
5 5
1 2
1 3
1 4
2 3
5 4

output
3
1 4 5

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> dis; // distance array
vector<int> par; // parent array to reconstruct paths
vector<vector<int>> adj;

const int INF = 1e9 + 7;

void bfs(int src) { // src = source node

	queue<int> q;

	// initialize the source node
	dis[src] = 0;
	par[src] = -1; // the source node has no parent
	q.push(src);

	while (!q.empty()) {

		int u = q.front(); // u = current node
		q.pop();

		// explore all the neighbors of the current node
		for (int v : adj[u]) { // v = neighbor of u
			if (dis[v] == INF) { // if dis[v] is still INF, it means we haven't visited it yet.
				dis[v] = dis[u] + 1; // distance to neighbor from src is the distance of current node from src + 1
				par[v] = u;
				q.push(v);
			}
		}
	}

}

vector<int> getPath(int dst) { // dst = destination node
	// if the destination is unreachable, return an empty path
	if (dis[dst] == INF) {
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

	int n, m;
	cin >> n >> m;

	dis.assign(n, INF);
	par.assign(n, -1);
	adj.assign(n, {});

	// read the graph

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--; // convert 1-based input to 0-based indexing
		adj[u].push_back(v);
		adj[v].push_back(u); // comment out this line if the graph is directed
	}

	bfs(0); // find shortest paths from node 0

	vector<int> path = getPath(n - 1);

	if (path.empty()) {
		cout << "IMPOSSIBLE";
	} else {
		cout << (int)path.size() << "\n";
		for (int i = 0; i < (int)path.size(); i++) {
			cout << path[i] + 1 << " "; // convert 0-based output to 1-based output
		}
	}

	return 0;
}