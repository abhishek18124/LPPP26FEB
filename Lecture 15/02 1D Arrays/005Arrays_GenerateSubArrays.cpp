#include<iostream>
#include<vector>

using namespace std;

// time : O(n^3)

void generateSubarrays(const vector<int>& arr, int n) {

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// generate the subarray that starts
			// at the ith index and ends at the
			// jth index

			// cout << i << j << '\n';

			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}

			cout << endl;

		}

		cout << '\n';

	}

}

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();

	generateSubarrays(arr, n);

	return 0;
}