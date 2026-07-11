// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int arr[], int lo, int mid, int hi) {

	// arr[lo...mid] is sorted

	// arr[mid+1..hi] is sorted

	// we want to merge arr[lo...mid] and arr[mid+1..hi]

	// such that arr[lo...hi] becomes sorted

	int temp[100];

	int i = lo; // to iterate over arr[lo..mid]
	int j = mid + 1; // to iterate over arr[mid+1..hi]
	int k = lo; // to iterate over temp[lo...hi]

	while (i <= mid and j <= hi) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while (i <= mid) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	while (j <= hi) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	// temp[lo...hi] is sorted

	for (int i = lo; i <= hi; i++) {
		arr[i] = temp[i];
	}

	// arr[lo...hi] is sorted

}

void f(int arr[], int lo, int hi) {

	// base case

	if (lo == hi) {
		return;
	}

	// recursive case

	// f(lo, hi) : sort the arr[lo..hi]

	// 1. divide the array around the mid-point
	int mid = lo + (hi - lo) / 2;

	// 2. ask your friend to sort arr[lo...mid]

	f(arr, lo, mid);

	// 2. ask your friend to sort arr[mid+1..hi]

	f(arr, mid + 1, hi);

	// 3. merge the two sorted subarrays i.e. arr[lo...mid] and arr[mid+1...hi]

	merge(arr, lo, mid, hi);

}

int main() {

	int arr[] = {60, 50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	f(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}