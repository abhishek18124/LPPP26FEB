#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// time : O(n)
// space: O(n) due to x[]

int maximumSubarraySumUsingKadanes(const vector<int>& arr, int n) {

	vector<int> x(n);
	x[0] = arr[0];
	int maxSoFar = x[0];

	for (int i = 1; i < n; i++) {
		x[i] = max(x[i - 1] + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x[i]);
	}

	return maxSoFar;

}

// time : O(n)
// space: O(1)

int maximumSubarraySumUsingKadanesSpaceOptimised(const vector<int>& arr, int n) {


	int x = arr[0]; // x init. represents x[0]
	int maxSoFar = x;

	for (int i = 1; i < n; i++) {
		x = max(x + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x);
	}

	return maxSoFar;

}

int main() {

	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = arr.size();

	cout << maximumSubarraySumUsingKadanes(arr, n) << "\n";

	cout << maximumSubarraySumUsingKadanesSpaceOptimised(arr, n) << "\n";

	return 0;
}