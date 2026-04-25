#include<iostream>

using namespace std;

int multiply(int a, int b) {
	// int c = a * b;
	// return c;
	return a * b;
}

int main() {

	cout << multiply(4, 5) << '\n';

	int ans = multiply(3, 7);
	cout << ans << '\n';

	cout << 20 + 4 + multiply(2, 2) << '\n';

	return 0;
}