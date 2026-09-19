#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n, m; // n = number of nodes, m = number of edges
	cin >> n >> m;

	// map<string, vector<string>> adj;
	map<string, set<string>> adj;
	for (int i = 0; i < m; i++) {
		string u, v;
		cin >> u >> v;
		// adj[u].push_back(v);
		// adj[v].push_back(u);
		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (auto [u, ngblist] : adj) {
		cout << "neighbors(" << u << ") : ";
		for (const string& v : ngblist) {
			cout << v << " ";
		}
		cout << endl;
	}

	return 0;
}