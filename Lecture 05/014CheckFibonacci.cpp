#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 or n == 1) {
		cout << true;
	} else {
		// n >= 2

		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		while (true) {

			int c = a + b;

			if (c == n) {
				cout << true;
				break;
			}

			if (c > n) {
				cout << false;
				break;
			}

			// c < n

			a = b;
			b = c;

		}
	}

	return 0;
}