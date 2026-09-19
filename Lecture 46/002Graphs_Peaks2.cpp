/*

https://atcoder.jp/contests/abc166/tasks/abc166_c

input
4 3
1 2 3 4
1 3
2 3
2 4

output
2

input
6 5
8 6 9 1 2 1
1 3
4 2
4 3
4 6
4 6

output
3

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef pair<int, int> pii;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> h(n); // array to store the heights of the observatories
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vector<int> adj(n, 0); // adj[i] stores the max height among all the neighbors of node i.

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--; // convert 1-based input to 0-based indexing
		adj[u] = max(adj[u], h[v]);
		adj[v] = max(adj[v], h[u]);
	}

	int ans = 0; // stores no. of "good" observatories

	for (int i = 0; i < n; i++) {
		if (h[i] > adj[i]) {
			// the ith observatory is good
			ans++;
		}
	}

	cout << ans;

	return 0;
}