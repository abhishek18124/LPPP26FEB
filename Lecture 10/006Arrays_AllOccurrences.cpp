#include<iostream>

using namespace std;

int main() {

	int arr[100]; // based on constraints

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int t;
	cin >> t;

	int cnt = 0; // to track no. of times we found 't' in arr[]

	for (int i = 0; i < n; i++) {

		if (arr[i] == t) {

			cout << i << " ";
			cnt++;

		}

	}

	if (cnt == 0) {
		// 't' is not found
		cout << -1;
	}

	return 0;
}