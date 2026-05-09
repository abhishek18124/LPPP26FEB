#include<iostream>
#include<vector>

using namespace std;

int binarySearch(const vector<int>& arr, int n, int t) {

	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int m = (s + e) / 2;
		if (arr[m] == t) {
			// you've found the 't' at index m
			return m;
		} else if (t > arr[m]) {
			s = m + 1;
		} else {
			// t < arr[m]
			e = m - 1;
		}
	}

	// here, s > e which means 't' is not present in the arr[]
	return -1;

}

int main() {

	vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
	int n = arr.size();

	int t = 100;

	cout << binarySearch(arr, n, t) << endl;

	return 0;
}