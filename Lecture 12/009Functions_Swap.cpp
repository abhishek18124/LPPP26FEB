#include<iostream>

using namespace std;

void mySwap(int& x, int& y) {
	// int temp = x;
	// x = y;
	// y = temp;
	x = x + y;
	y = x - y;
	x = x - y;
}

int main() {

	int a = 25;
	int b = 35;

	cout << a << " " << b << endl;

	mySwap(a, b);

	cout << a << " " << b << endl;

	return 0;
}