#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// int i = 0;

	// for (; i < n; i++) {
	// 	cout << i << " ";
	// }

	// cout << "\n" << i;

	// cout << endl;

	// for (; ;) {
	// 	cout << "*";
	// }

	for (int i = 1, j = n; i < j; i++, j--) {
		cout << i << " " << j << endl;
	}

	return 0;
}