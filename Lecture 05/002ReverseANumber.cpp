#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int ans = 0; // to store the reverse of 'n'

	while (n > 0) {
		int dig = n % 10;
		ans = ans * 10 + dig;
		n = n / 10;
	}

	cout << ans << endl;

	return 0;
}