/*

https://codeforces.com/problemset/problem/986/A

input
5 5 4 3
1 2 4 3 2
1 2
2 3
3 4
4 1
4 5

output
2 2 2 2 3

input
7 6 3 2
1 2 3 3 2 2 1
1 2
2 3
3 4
2 5
5 6
6 7

output
1 1 1 2 2 1 1

*/

#include<iostream>
#include<queue>
#include<algorithm> // required for std::sort / std::nth_element
#include<numeric> // required for std::accumulate

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k, s;
	cin >> n >> m >> k >> s;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--; // convert 1-based input to 0-based indexing for goods
	}

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--; // convert 1-based input to 0-based indexing for nodes
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// costs[i][j] stores the shortest distance from town "i" to any town producing good "j"
	vector<vector<int>> costs(n, vector<int>(k));
	const int INF = 1e9 + 7;

	// run a multi-source bfs for each type of good
	for (int j = 0; j < k; j++) {

		vector<int> dis(n, INF);
		queue<int> q;

		// multi-source bfs initialization : push all towns that produce good j
		for (int i = 0; i < n; i++) {
			if (a[i] == j) {
				dis[i] = 0;
				q.push(i);
			}
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : adj[u]) {
				if (dis[v] == INF) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}

		// record the distances for this specific good type "j"
		for (int i = 0; i < n; i++) {
			costs[i][j] = dis[i];
		}

	}

	// for each town, find the sum of the "s" closest distinct goods
	for (int i = 0; i < n; i++) {
		sort(costs[i].begin(), costs[i].end()); // O(klogk)
		// nth_element(costs[i].begin(), costs[i].begin() + (s - 1), costs[i].end()); // on avg. O(k)
		int totalCost = accumulate(costs[i].begin(), costs[i].begin() + s, 0); // accumulate the first "s" elements
		cout << totalCost << " ";
	}

	return 0;
}