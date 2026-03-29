#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		// for the ith row, first print n-i spaces

		for (int j = 1; j <= n - i; j++) {
			cout << "  ";
		}

		// then print i nos. starting with i in inc. order

		int num = i;

		for (int j = 1; j <= i; j++) {
			cout << num << " ";
			num++;
		}

		// then print i-1 more nos. starting with 2i-2 in dec. order

		num = 2 * i - 2;

		for (int j = 1; j <= i - 1; j++) {
			cout << num << " ";
			num--;
		}

		cout << endl;

	}

	return 0;
}