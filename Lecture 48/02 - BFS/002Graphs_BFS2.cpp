/*

********************************************
Implementation of BFS for Disconnected Graph
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
bfs(0): 0 2 3 5 1 6 4
bfs(7): 7 9 8 10 11
bfs(12): 12 13 14 15

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> vis; // keeps track of visited nodes
vector<vector<int>> adj; // adjacency list

void bfs(int src) { // src = source node

  queue<int> q;

  // mark the source node as visited
  vis[src] = true;
  q.push(src);


  while (!q.empty()) {

    int u = q.front(); // u = current node
    q.pop();

    // process the current node
    cout << u << " ";

    // explore all the neighbors of the current node
    for (int v : adj[u]) { // v = neighbor of u
      if (!vis[v]) { // if the neighbor hasn't been visited yet, visit it
        vis[v] = true;
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
      cout << "bfs(" << i << "): ";
      bfs(i);
      cout << '\n';
    }
  }

  return 0;

}