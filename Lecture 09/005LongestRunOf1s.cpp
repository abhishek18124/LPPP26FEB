#include<iostream>
#include<bitset>

using namespace std;

int main() {

	int n;
	cin >> n;

	// cout << bitset<32>(n) << endl;

	int cnt = 0;
	int maxSoFar = 0;

	while (n != 0) {
		int zerothBit = n & 1;
		if (zerothBit) {
			cnt++;
			maxSoFar = max(maxSoFar, cnt);
			// if(cnt > maxSoFar) {
			// 	maxSoFar = cnt;
			// }
		} else {
			// zerothBit == 0
			cnt = 0;
		}
		n = n >> 1;
	}

	cout << maxSoFar << endl;

	return 0;
}