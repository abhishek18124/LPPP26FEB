#include<iostream>

using namespace std;

// time : O(n)
// space: O(n)

int f(int X[], int n, int i) {

	// base case

	if (i == n) {
		// f(n) : find the sum of X[n..n-1] = {}
		return 0;
	}

	// recursive case

	// f(i) : find the sum of X[i...n-1]

	// 1. ask your friend to find the sum of X[i+1...n-1]

	int A = f(X, n, i + 1);

	// 2. use answer from your friend to build the final answer

	return X[i] + A;

}

int main() {

	int X[] = {5, 2, 1, 4};
	int n = sizeof(X) / sizeof(int);

	cout << f(X, n, 0) << endl;

	return 0;
}