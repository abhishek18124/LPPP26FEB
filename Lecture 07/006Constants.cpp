#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int x = 10;
	cout << x << endl;

	x++;
	cout << x << endl;

	const int y = 20;
	cout << y << endl;

	// y++; // error

	const int z;

	z = 10;

	// 1. const var must always be initialized
	// 2. const var are read only var, so they cannot be modified

	return 0;
}