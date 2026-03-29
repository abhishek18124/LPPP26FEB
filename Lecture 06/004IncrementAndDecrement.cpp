#include<iostream>

using namespace std;

int main() {

	int x = 0;

	x++; // or ++x

	cout << "x : " << x << endl;

	int y = 1;

	y--; // or --y

	cout << "y : " << y << endl;

	int a = 20;
	int b = a++;
	cout << a << " " << b << endl;

	int c = 20;
	int d = ++c;
	cout << c << " " << d << endl;

	return 0;
}