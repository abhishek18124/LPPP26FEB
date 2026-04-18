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

	// time : O(n)

	bool flag = false; // assume 't' is not present

	for (int i = 0; i < n; i++) {

		if (arr[i] == t) {

			cout << i << " ";
			flag = true;

		}

	}

	if (flag == false) {
		// 't' is not found
		cout << -1;
	}

	return 0;
}