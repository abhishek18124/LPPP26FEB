#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	// for (int& x : v) {
	// 	cin >> x;
	// }

	// for (int& x : v) {
	// 	cin >> x;
	// }

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	for (int x : v) {
		cout << x << " ";
	}

	cout << endl;

	for (int& x : v) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}