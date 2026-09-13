#include<iostream>

using namespace std;

int main() {

	int arr[] = {2, 3, 2, 4, 0, 2, 0};
	int n = sizeof(arr) / sizeof(int);
	int k = 6;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the window

	int wSum = 0; // to store the window sum

	int maxWLenSoFar = 0; // to track the length of the longest
	// window which has a sum equals to k

	// time : O(n)
	// space: O(1)

	while (j < n) {

		// expand the window
		wSum += arr[j];
		j++;

		// check for the violation of the window property
		if (wSum > k) {
			// start shrinking the window
			while (wSum > k) {
				wSum -= arr[i];
				i++;
			}
		}

		// check for the validity of the window, and update the answer
		if (wSum == k) {
			maxWLenSoFar = max(maxWLenSoFar, j - i);
		}

		// continue expansion of the window

	}

	cout << maxWLenSoFar << endl;

	return 0;
}