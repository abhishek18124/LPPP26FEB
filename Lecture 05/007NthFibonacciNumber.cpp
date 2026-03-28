#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 or n == 1) {
		cout << n << endl;
	} else {
		// n >= 2
		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.
		int i = 1;

		// time : (n-1)*const ~ O(n)
		// space: O(1)

		while (i <= n - 1) {
			int c = a + b;
			a = b;
			b = c;
			i = i + 1;
		}

		cout << b << endl;
	}

	return 0;
}