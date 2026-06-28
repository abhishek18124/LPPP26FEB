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

	while (e - s > error) {

		double mid = s + (e - s) / 2;
		if (mid * mid <= n) {
			s = mid;
		} else {
			e = mid;
		}

	}

	cout << setprecision(7) << fixed << s << endl;

	return 0;
}