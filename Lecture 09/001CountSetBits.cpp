#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 20;
	int cnt = 0; // to track the no. of set bits in 'n'

	for (int k = 0; k < 32; k++) {
		// check if the kth bit of n is set or not
		if ((n >> k) & 1) {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}