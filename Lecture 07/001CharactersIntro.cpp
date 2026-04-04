#include<iostream>

using namespace std;

int main() {

	char ch = 'c';
	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 'X';
	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 'B';
	cout << ch << endl;
	cout << (int)ch << endl;

	ch = '3';
	cout << ch << endl;
	cout << (int)ch << endl;

	int x = ch - '0';
	cout << x << endl;

	ch = '9';
	x = ch - '0';
	cout << x << endl;

	int y = 'A';
	cout << y << endl;

	ch = 67;
	cout << ch << endl;

	ch = 42;
	cout << ch << endl;

	ch = '#';
	cout << (int)ch << endl;

	return 0;

}