#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int s = 0;
	int e = n;

	double ans;

	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (mid * mid <= n) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}

	while (ans * ans <= n) {
		ans = ans + 0.1;
	}

	ans = ans - 0.1;

	cout << ans << endl;

	cout << sqrt(n) << endl;

	return 0;
}