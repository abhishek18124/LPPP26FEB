/*

**************************************
Cycle Detection in an Undirected Graph
**************************************

input
3 3
0 1
0 2
1 2

output
true

*/

#include<iostream>
#include<vector>

using namespace std;

vector<bool> vis; // keeps track of visited nodes
vector<vector<int>> adj; // adjacency list

bool dfs(int u, int p) { // u = current node, p = parent node (where we just came from)

  // 1. mark the current node as visited
  vis[u] = true;

  // 2. explore all the neighbors of the current node
  for (int v : adj[u]) { // v = neighbor of u
    if (!vis[v]) {
      // the neighbor hasn't been visited, recursively visit it.
      if (dfs(v, u)) {
        // a cycle is found in the sub-component of the neighbor
        // hence a cycle is found in the component of the current node
        return true;
      }
    } else {
      // the neighbor has been visited, check if edge (u, v) is a back-edge
      if (v != p) {
        // (u, v) is a back-edge hence we've found a cycle in the component of the current node
        return true;
      }
    }
  }

  return false; // no cycles found in the component of the current node

}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vis.assign(n, false);
  adj.assign(n, {});

  // read the graph
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool flag = false; // assume cycle is not present in the graph

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      if (dfs(i, -1)) {
        // a cycle found in the component of node i, hence cycle found in the graph
        flag = true;
        break;
      }
    }
  }

  flag ? cout << "true" : cout << "false";

  return 0;

}