#include<iostream>

using namespace std;

int main() {

	int p;
	cin >> p;

	int r;
	cin >> r;

	int t;
	cin >> t;

	// int p, r, t;
	// cin >> p >> r >> t;

	cout << p * r * t / 100 << endl;
	cout << (p * r * t) / 100.0 << endl;
	cout << ((double)p * r * t) / 100 << endl;

	double si = ((double)p * r * t) / 100;
	cout << si << endl;

	return 0;
}