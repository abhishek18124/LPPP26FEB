#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main() {

	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = arr.size();

	// time : n + n^2 ~ O(n^2)
	// space: O(n) due to pSum[]

	// 1. precompute pSum[]

	vector<int> pSum(n);

	pSum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		pSum[i] = pSum[i - 1] + arr[i];
	}

	// 2. iterate over all the subarrays and track the maximum subarray sum

	int maxSoFar = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// find the sum of subarray that
			// starts at the ith index and
			// ends at the jth index
			int sum = i == 0 ? pSum[j] : pSum[j] - pSum[i - 1];
			maxSoFar = max(maxSoFar, sum);
		}
	}

	cout << maxSoFar << "\n";

	return 0;
}