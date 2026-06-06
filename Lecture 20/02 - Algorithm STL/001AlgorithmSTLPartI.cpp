#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	// vector<int> v = {50, 20, 10, 40, 30};
	// sort(v.begin(), v.end());
	// for (int i = 0; i < (int)v.size(); i++) {
	// 	cout << v[i] << " ";
	// }
	// cout << endl;

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// 1. sorting a sequence using built-in sort() in O(nlogn) // introsort used

	sort(arr, arr + n); // [0, n)

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 2. reversing a sequence using the built-in reverse()

	reverse(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;


	// 3. reversing a sequence in-range using the built-in reverse()

	reverse(arr + 2, arr + 4); // [2, 4)

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
