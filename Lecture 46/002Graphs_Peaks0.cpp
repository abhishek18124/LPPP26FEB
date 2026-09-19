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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> h(n); // array to store the heights of the observatories
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vector<vector<int>> adj(n); // adj[i] stores all the neighbors of node i

	// read edges

	for (int i = 0; i < m; i++) {
		int u, v; // endpoints of the edge
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment out this line if the graph is directed
	}

	int ans = 0; // stores no. of good observatories

	for (int i = 0; i < n; i++) {

		// is ith observatory good ?

		bool flag = true; // assume ith observatory is good

		for (int v : adj[i]) {
			if (h[v] >= h[i]) {
				// ith observatory is not good
				flag = false;
				break;
			}
		}

		if (flag) {
			ans++;
		}

	}

	cout << ans << endl;

	// time : O(n + 2m) or O(|V| + 2|E|)

	return 0;
}