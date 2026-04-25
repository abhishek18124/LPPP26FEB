#include<iostream>

using namespace std;

int incr(int a) {
	a++;
	return a;
}

int main() {

	int a = 10;

	a = incr(a);

	cout << a << endl;

	return 0;
}