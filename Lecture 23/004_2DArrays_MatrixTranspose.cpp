/*

	Constraints :

	0 < n <= 10

*/

#include<iostream>

using namespace std;

// time : (n^2 - n)/2 * const ~ O(n^2)

void transpose(int mat[][10], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(mat[i][j], mat[j][i]);
		}
	}

}

int main() {

	int mat[][10] = {
		{10, 20, 30},
		{40, 50, 60},
		{70, 80, 90}
	};

	int n = 3;

	cout << "matrix before transpose = " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	transpose(mat, n);

	cout << "matrix after transpose = " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}