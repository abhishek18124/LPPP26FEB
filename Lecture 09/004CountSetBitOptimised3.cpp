#include<iostream>

using namespace std;

int main() {

	int n = 15;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n != 0) {
		cnt++;
		// clear the rightmost set bit of n
		n = n & (n - 1);
	}

	cout << cnt << endl;

	cout << __builtin_popcount(15) << endl;
	cout << __builtin_popcount(42) << endl;
	cout << __builtin_popcount(20) << endl;

	long long x = 1e12;
	cout << x << endl;
	cout << __builtin_popcountll(x) << endl;

	return 0;
}