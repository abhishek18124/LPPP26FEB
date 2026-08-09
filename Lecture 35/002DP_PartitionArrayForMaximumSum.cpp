// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:

	int f(const vector<int>& arr, int k, int n, int i, vector<int>& dp) {

		// lookup
		if (dp[i] != -1) {
			return dp[i];
		}

		// base case
		if (i == n) {
			return dp[i] = 0;
		}

		// recursive case

		// f(i) : find the maximum sum from partitioning arr[i...n-1]

		// decide the next cut

		int maxSoFar = 0;
		int maxij = 0;

		for (int j = i; j <= i + k - 1 and j < n; j++) {
			maxij = max(maxij, arr[j]);
			maxSoFar = max(maxSoFar,
			               (j - i + 1) * maxij + f(arr, k, n, j + 1, dp));

		}

		return dp[i] = maxSoFar;

	}

	// time : O(nk)
	// space: O(n) due to dp[]

	int fBottomUp(const vector<int>& arr, int k, int n) {
		vector<int> dp(n + 1);
		dp[n] = 0; // at the nth index of dp[] we store f(n)
		for (int i = n - 1; i >= 0; i--) {
			// dp[i] = max. sum from partition arr[i...n-1]
			// f(i) : find the maximum sum from partitioning arr[i...n-1]

			// decide the next cut

			int maxSoFar = 0;
			int maxij = 0;

			for (int j = i; j <= i + k - 1 and j < n; j++) {
				maxij = max(maxij, arr[j]);
				maxSoFar = max(maxSoFar,
				               (j - i + 1) * maxij + dp[j + 1]);

			}
			dp[i] = maxSoFar;
		}
		return dp[0]; // at the 0th index of dp[] we store f(0)
	}

	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = (int)arr.size();
		// vector<int> dp(n + 1, -1);
		// return f(arr, k, n, 0, dp);
		return fBottomUp(arr, k, n);
	}
};