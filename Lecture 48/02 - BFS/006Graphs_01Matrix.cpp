/*

**********************************
IMPLEMENTATION OF MULTI-SOURCE BFS
**********************************

https://leetcode.com/problems/01-matrix/

*/

class Solution {
public:

    // time : O(mn)

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        const int INF = 1e9 + 7;

        // dis acts as both our distance tracker and visited array
        vector<vector<int>> dis(m, vector<int>(n, INF));

        queue<pair<int, int>> q;
        // push all starting points (0s) into the queue at distance 0.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        // direction arrays for moving right, left, down, up
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!q.empty()) {

            auto [i, j] = q.front(); // C++17 structured binding to unpack the pair cleanly
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ii = i + dx[k];
                int jj = j + dy[k];

                if (ii >= 0 && ii < m && jj >= 0 && jj < n &&
                        dis[ii][jj] == INF) {
                    dis[ii][jj] = dis[i][j] + 1;
                    q.push({ii, jj});
                }
            }
        }

        return dis;

    }
};