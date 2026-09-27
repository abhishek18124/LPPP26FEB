/*

*********************************
Dijkstra's Algorithm on a 2D Grid
*********************************

https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

*/

// pair for coordinates {row, col}
typedef pair<int, int> pii;
// nested pair for pq {distance, {row, col}}
typedef pair<int, pii> pipii;

const int INF = 1e9;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = (int)grid[0].size();

        // dist[i][j] tracks the minimum obstacles removed to reach cell (i, j)
        vector<vector<int>> dist(m, vector<int>(n, INF));
        dist[0][0] = 0; // dist[0][0] = grid[0][0];

        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push({dist[0][0], {0, 0}});

        // direction arrays for moving right, left, down, up
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!pq.empty()) {

            // unpack the nested pair using C++17 structured bindings
            auto [du, u] = pq.top();
            auto [i, j] = u;
            pq.pop();

            // lazy deletion: ignore stale distances
            if (du > dist[i][j]) continue;

            // explore all 4 adjacent cells
            for (int k = 0; k < 4; k++) {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (ii >= 0 and ii < m and jj >= 0 and jj < n and
                        dist[ii][jj] > du + grid[ii][jj]) {

                    dist[ii][jj] = du + grid[ii][jj];
                    pq.push({dist[ii][jj], {ii, jj}});

                }
            }
        }

        return dist[m - 1][n - 1];

    }
};