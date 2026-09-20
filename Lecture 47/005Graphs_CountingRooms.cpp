/*

https://cses.fi/ckvo8q5wh/task/1192

input
5 8
########
#..#...#
####.#.#
#..#...#
########

output
3

*/
#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<vector<bool>> vis;
vector<vector<char>> maze;

void dfs(int i, int j) {

	vis[i][j] = true;

	int ii = i;
	int jj = j + 1;

	if (ii >= 0 and ii < N and jj >= 0 and jj < M and maze[ii][jj] == '.' and !vis[ii][jj]) {
		dfs(ii, jj);
	}

	ii = i;
	jj = j - 1;

	if (ii >= 0 and ii < N and jj >= 0 and jj < M and maze[ii][jj] == '.' and !vis[ii][jj]) {
		dfs(ii, jj);
	}

	ii = i + 1;
	jj = j;

	if (ii >= 0 and ii < N and jj >= 0 and jj < M and maze[ii][jj] == '.' and !vis[ii][jj]) {
		dfs(ii, jj);
	}

	ii = i - 1;
	jj = j;

	if (ii >= 0 and ii < N and jj >= 0 and jj < M and maze[ii][jj] == '.' and !vis[ii][jj]) {
		dfs(ii, jj);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	vis.assign(N, vector<bool>(M, false));

	maze.assign(N, vector<char>(M, ' '));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maze[i][j] == '.' and !vis[i][j]) {
				ans++;
				dfs(i, j);
			}
		}
	}

	cout << ans;

	return 0;
}