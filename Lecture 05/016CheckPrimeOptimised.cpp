#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;

	while (i * i <= n) {

		if (n % i == 0) {

			// you've found a factor of n in the
			// range 2 to n-1

			cout << n << " is not prime" << endl;
			break;

		}

		i = i + 1;

	}

	if (i * i > n) {
		cout << n << " is prime" << endl;
	}

	return 0;
}