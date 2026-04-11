#include<iostream>

using namespace std;

int main() {

	int n = 32;

	int mask = 0x55555555;

	if (((n & (n - 1)) == 0) && ((n & mask) == n)) {
		cout << n << " is a power of 4" << endl;
	} else {
		cout << n << " is not a power of 4" << endl;
	}

	return 0;
}