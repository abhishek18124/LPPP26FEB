#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	double ans = 0;

	while (ans * ans <= n) {
		ans = ans + 1;
	}

	ans = ans - 1;

	int i = 1;
	double incFactor = 0.1;

	while (i <= p) {

		while (ans * ans <= n) {
			ans = ans + incFactor;
		}

		ans = ans - incFactor;
		incFactor = incFactor / 10;

		i = i + 1;

	}

	cout << ans << endl;

	return 0;
}