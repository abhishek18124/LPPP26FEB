#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int sum = 0; // to track the sum of digits of 'n'

	while (n > 0) {
		int dig = n % 10;
		sum = sum + dig;
		n = n / 10;
	}

	cout << sum << endl;

	return 0;
}