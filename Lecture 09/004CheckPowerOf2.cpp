#include<iostream>

using namespace std;

int main() {

	int n = 32;

	(n & (n - 1)) == 0 ? cout << n << " is power of 2" << endl :
	                          cout << n << " is not a power of 2" << endl;

	return 0;
}