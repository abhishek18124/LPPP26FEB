/*

*****************************************
Implementation of BFS for Connected Graph
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
0 1 2 3 4 5 6 7 8

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> vis; // keeps track of visited nodes
vector<vector<int>> adj; // adjacency list

// time : O(V + 2E)
// space: O(V)

void bfs(int src) { // s = source node

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

  bfs(0); // node 0 is the source node

  return 0;
}