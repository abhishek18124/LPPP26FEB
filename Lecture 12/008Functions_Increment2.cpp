#include<iostream>

using namespace std;

void incr(int& ref) {
	ref++;
}

int main() {

	int a = 10;

	incr(a);

	cout << a << endl;

	return 0;
}