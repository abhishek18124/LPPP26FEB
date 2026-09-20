/*

********************************************
Implementation of DFS for Disconnected Graph
********************************************

input
16 16
0 2
0 3
1 3
1 4
2 5
3 5
3 6
4 6
7 9
8 9
9 10
9 11
12 13
12 14
13 15
14 15

output
dfs(0): 0 2 5 3 1 4 6
dfs(7): 7 9 8 10 11
dfs(12): 12 13 15 14

*/

#include<iostream>
#include<vector>

using namespace std;

vector<bool> vis; // keeps track of visited nodes
vector<vector<int>> adj; // adjacency list

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
  adj.assign(n, {});;

  // read the graph
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // comment out this line if the graph is directed
  }

  int cnt = 0; // stores no. of components in the graph

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << "dfs(" << i << "): ";
      dfs(i);
      cnt++;
      cout << '\n';
    }
  }

  cout << "number of components = " << cnt << '\n';

  return 0;

}