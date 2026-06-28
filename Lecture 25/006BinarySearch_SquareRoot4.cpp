#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {

	int n;
	cin >> n;

	double s = 0;
	double e = n;

	double error = 1e-7;

	double ans = 0.0;

	int numIterations = 60;

	for (int i = 1; i <= numIterations; i++) {
		double mid = s + (e - s) / 2;
		if (mid * mid <= n) {
			ans = mid;
			s = mid + error;
		} else {
			e = mid - error;
		}
	}

	cout << setprecision(7) << fixed << ans << endl;

	return 0;
}