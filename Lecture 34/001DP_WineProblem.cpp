/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

	// n <= 100

*/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

// time : O(2^n)
// space: O(n) due to fn call stack

int cntr1 = 0;

int f(const vector<int>& p, int i, int j, int y) {

	cntr1++;

	// base case

	if (i == j) {
		return y * p[i];
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle in the yth year

	// option 2 : sell the jth bottle in the yth year

	return max(y * p[i] + f(p, i + 1, j, y + 1),
	           y * p[j] + f(p, i, j - 1, y + 1));

}

int dp[100][100][101];
int cntr2 = 0;

int fTopdown(const vector<int>& p, int i, int j, int y) {


	cntr2++;

	// lookup
	if (dp[i][j][y] != -1) {
		return dp[i][j][y];
	}

	// base case

	if (i == j) {
		return  dp[i][j][y] = y * p[i];
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle in the yth year

	// option 2 : sell the jth bottle in the yth year

	return dp[i][j][y] = max(y * p[i] + fTopdown(p, i + 1, j, y + 1),
	                         y * p[j] + fTopdown(p, i, j - 1, y + 1));

}

int main() {

	vector<int> p = {2, 3, 5, 1, 4, 2, 3, 5, 1, 4, 2, 3, 5, 1, 4};
	int n = p.size();

	cout << f(p, 0, n - 1, 1) << endl;

	// vector<vector<vector<int>>> dp(n,
	//                                vector<vector<int>>(n,
	//                                        vector<int>(n + 1, -1)));
	// int arr[n][n][n + 1];

	memset(dp, -1, sizeof(dp));

	cout << fTopdown(p, 0, n - 1, 1) << endl;

	cout << cntr1 << endl;
	cout << cntr2 << endl;

	return 0;
}