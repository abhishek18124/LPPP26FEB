#include<iostream>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	cout << __builtin_popcount(n ^ m) << endl;

	return 0;
}