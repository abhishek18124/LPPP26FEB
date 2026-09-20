/*

*****************************************
Implementation of DFS for Connected Graph
*****************************************

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
0 1 3 6 4 2 5 7 8

*/

#include<iostream>
#include<vector>

using namespace std;

vector<bool> vis; // keeps track of visited nodes
vector<vector<int>> adj; // adjacency list

// time : O(n + 2m) or O(V + 2E)
// space: n for vis[] + n due to fn call stack ~ O(n) or O(V)

void dfs(int u) { // u = current node

  // 1. mark the current node as visited
  vis[u] = true;

  // 2. process the current node
  cout << u << " ";

  // 3. explore all the neighbors of the current node
  for (int v : adj[u]) { // v = neighbor of u
    if (!vis[v]) { // if the neighbor hasn't been visited yet
      dfs(v); // recursively visit it
    }
  }

}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vis.assign(n, false);
  adj.assign(n, {}); // adj.assign(n, vector<int>());

  // read the graph
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // comment out this line if the graph is directed
  }

  dfs(0); // node 0 is the src node

  return 0;
}