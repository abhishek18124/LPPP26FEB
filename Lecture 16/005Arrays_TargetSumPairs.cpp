#include<iostream>
#include<vector>

using namespace std;

// time : O(n^2)

int targetSumPair(const vector<int>& arr, int n, int t) {

	int cnt = 0; // to track no. of valid pairs in the arr[]

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			int pairSum = arr[i] + arr[j];
			if (pairSum == t) {
				cnt++;
			}
		}
	}

	return cnt;

}

// time : O(n)
// space: O(1)

int targetSumPairOptimised(const vector<int>& arr, int n, int t) {

	int i = 0;
	int j = n - 1;

	int cnt = 0; // tracks no. of valid pairs in arr[]

	while (i < j) {

		int pairSum = arr[i] + arr[j];
		if (pairSum == t) {
			cnt++; i++; j--;
		} else if (pairSum > t) {
			j--;
		} else {
			// pairSum < t
			i++;
		}

	}

	return cnt;

}

int main() {

	vector<int> arr = {10, 20, 30, 40, 50, 60};
	int n = arr.size();
	int t = 60;

	cout << targetSumPair(arr, n, t) << "\n";

	cout << targetSumPairOptimised(arr, n, t) << "\n";

	return 0;
}