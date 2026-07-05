#include<iostream>

using namespace std;

int f(int n) {

	// baes case

	if (n == 0) {
		// f(0) = find 0!
		return 1;
	}

	// recursive case

	// f(n) : find n!

	// 1. ask your friend to find n-1!

	int A = f(n - 1);

	// 2. use the answer given by your friend to build the final answer

	return n * A;

}

int main() {

	int n = 5;

	cout << f(n) << endl;

	return 0;
}