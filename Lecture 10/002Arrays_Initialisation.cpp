#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};
	int n = 5;

	cout << "A[0] = " << A[0] << endl;
	cout << "A[1] = " << A[1] << endl;
	cout << "A[2] = " << A[2] << endl;
	cout << "A[3] = " << A[3] << endl;
	cout << "A[4] = " << A[4] << endl << endl;

	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "] = " << A[i] << endl;
	}

	cout << endl;

	for (int i = n - 1; i >= 0; i--) {
		cout << "A[" << i << "] = " << A[i] << endl;
	}

	cout << endl;

	int B[] = {100, 200, 300};

	cout << "sizeof(B) = " << sizeof(B) << "B" << endl;

	int m = sizeof(B) / sizeof(int);

	for (int i = 0; i < m; i++) {
		cout << "B[" << i << "] = " << B[i] << endl;
	}

	cout << endl;

	// int C[5] = {1, 2, 3, 4, 5, 6};

	int D[5] = {1, 2, 3};

	for (int i = 0; i < 5; i++) {
		cout << "D[" << i << "] = " << D[i] << endl;
	}

	cout << endl;

	// int E[5] = {};
	// int E[5] = {0};
	int E[5];
	memset(E, 0, sizeof(E)); // memset works for only 0 and -1

	for (int i = 0; i < 5; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	return 0;
}