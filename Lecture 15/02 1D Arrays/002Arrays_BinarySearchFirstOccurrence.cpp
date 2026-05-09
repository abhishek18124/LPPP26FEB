#include<iostream>
#include<vector>

using namespace std;

// time : O(logn)

int firstOcc(const vector<int>& arr, int n, int t) {

	int s = 0;
	int e = n - 1;

	int ans = -1;

	while (s <= e) {

		int m = (s + e) / 2;

		if (arr[m] == t) {
			ans = m;
			e = m - 1;
		} else if (t > arr[m]) {
			s = m + 1;
		} else {
			// t < arr[m]
			e = m - 1;
		}

	}

	return ans;

}

int main() {

	vector<int> arr = {10, 20, 30, 30, 30, 30, 40, 40, 50};
	int n = arr.size();

	int t = 40;

	cout << firstOcc(arr, n, t) << endl;

	return 0;
}