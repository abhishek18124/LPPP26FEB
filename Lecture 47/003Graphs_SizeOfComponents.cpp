/*

*****************************************
Size of Component in a Disconnected Graph
*****************************************

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
size(0)  = 7
size(7)  = 5
size(12) = 4

*/

#include<iostream>
#include<vector>

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
      cnt += dfs(v); // recursively visit it and add its component size
    }
  }

  return cnt; // return the total size of this component

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
    adj[v].push_back(u); // comment out this line if the graph is directed
  }

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << "size(" << i << ") = " << dfs(i) << "\n";
    }
  }

  return 0;

}