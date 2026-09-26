/*

https://leetcode.com/problems/is-graph-bipartite/

*/

class Solution {
public:

    // color array acts as both our "visited" tracker and our "color" assignment
    // -1 = unvisited
    //  0 = color A
    //  1 = color B

    vector<int> color;

    bool bfs(int src, const vector<vector<int>>& adj) {

        // 1. mark the source node with the first color (1)
        color[src] = 1;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int u = q.front(); // u = current node
            q.pop();

            for (int v : adj[u]) { // v = neighbor of u
                if (color[v] == -1) {
                    // neighbor is unvisited.
                    // assign it the opposite color of current node
                    color[v] = 1 - color[u];
                    q.push(v);
                } else {
                    // neighbor is already visited, check for a color conflict.
                    if (color[v] == color[u]) {
                        // two adjacent nodes have the exact same color hence component of node s is bipartite.
                        return false;
                    }
                }
            }
        }

        return true; // component of node s is bipartite
    }

    bool isBipartite(vector<vector<int>>& adj) {

        int n = (int)adj.size();

        color.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (bfs(i, adj) == false) {
                    // component of node i is not bipartite hence given graph is not bipartite
                    return false;
                }
            }
        }

        return true; // graph is bipartite

    }
};