#include<iostream>

using namespace std;

// time : O(y)
// space: O(y)

int f(int x, int y) {

	// base case

	if (y == 0) {
		// f(x, 0) = find pow(x, 0)
		return 1;
	}

	// recursive case

	// f(x, y) = find pow(x, y)

	// 1. ask your friend to find pow(x, y-1)

	int A = f(x, y - 1);

	// 2. use answer from your friend to get final answer

	return x * A;

}

int main() {

	int x = 3;
	int y = 3;

	cout << f(x, y) << endl;

	return 0;
}