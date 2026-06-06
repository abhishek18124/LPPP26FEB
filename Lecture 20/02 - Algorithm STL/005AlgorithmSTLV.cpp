#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {10, 10, 20, 30, 30, 30, 30, 30, 40, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// arr[] should sorted to use the following functions

	int key = 500;

	// 1. searching for a key in a sorted sequence in O(logn) using binary_search()

	if (binary_search(arr, arr + n, key)) {
		cout << key << " found" << endl;
	} else {
		cout << key << " not found" << endl;
	}

	// 2. finding lower bound for a key in a sorted sequence in O(logn) using lower_bound()

	key = 30;

	// lower_bound(key) returns the addr of the 1st element
	// in the array which is >= key

	auto it1 = lower_bound(arr, arr + n, key);
	cout << it1 - arr << endl;

	// 3. finding upper bound for a key in a sorted sequence in O(logn) using upper_bound()

	// upper_bound(key) returns the addr of the 1st element
	// in the array which is > key

	auto it2 = upper_bound(arr, arr + n, key);
	cout << it2 - arr << endl;

	// 4. counting the occurences of a key in a sorted sequence in O(logn)

	cout << it2 - it1 << endl;

	return 0;
}