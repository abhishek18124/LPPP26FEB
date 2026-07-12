// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int lo, int hi) {

	// partition the arr[lo...hi] around pivot i.e. arr[hi]

	int i = lo;
	int j = lo;
	int pivot = arr[hi];

	while (j < hi) {

		if (arr[j] < pivot) {
			// put arr[j] in the left partition
			swap(arr[i], arr[j]);
			i++;
		}

		j++;

	}

	swap(arr[i], arr[hi]);

	return i;

}

void f(int arr[], int lo, int hi) {

	// base case

	if (lo == hi) { // optional
		return;
	}

	if (lo > hi) { // mandatory
		return;
	}

	// recursive case

	// f(lo, hi) : sort the arr[lo...hi] using quickSort

	// 1. partition arr[lo...hi] around pivot

	int pIdx = partition(arr, lo, hi);

	// 2. ask your friend to quickSort left partition

	f(arr, lo, pIdx - 1);

	// 3. ask your friend to quickSort right partition

	f(arr, pIdx + 1, hi);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	f(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}