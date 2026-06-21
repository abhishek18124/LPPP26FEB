#include<vector>
#include<iostream>

using namespace std;

int main() {

	// vector<vector<int>> v;

	// vector<vector<int>> v(3, vector<int>(4));

	// vector<vector<int>> v(3, vector<int>(4, 1));

	// int m = v.size();
	// int n = v[0].size();

	int m, n;
	cin >> m >> n;

	vector<vector<int>> v(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}