#include<iostream>

using namespace std;

int computeSum(int arr[], int n) {

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	return sum;
}

void modify(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		(*(arr + i))++;
	}
}

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	modify(&arr[0], n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// cout << computeSum(arr, n) << endl;

	return 0;
}