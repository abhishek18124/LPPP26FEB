#include<iostream>
#include<climits>

using namespace std;

int main() {

	int arr[] = {20, 5, 0, 25, 15, 10};
	int n = sizeof(arr) / sizeof(int);

	int firstMaxSoFar = INT_MIN;
	int secondMaxSoFar = INT_MIN;
	int thirdMaxSoFar = INT_MIN;

	for (int i = 0; i < n; i++) {

		if (arr[i] > firstMaxSoFar) {
			thirdMaxSoFar = secondMaxSoFar;
			secondMaxSoFar = firstMaxSoFar;
			firstMaxSoFar = arr[i];
		} else if (arr[i] > secondMaxSoFar) {
			thirdMaxSoFar = secondMaxSoFar;
			secondMaxSoFar = arr[i];
		} else if (arr[i] > thirdMaxSoFar) {
			thirdMaxSoFar = arr[i];
		}

	}

	cout << firstMaxSoFar << endl;
	cout << secondMaxSoFar << endl;
	cout << thirdMaxSoFar << endl;

	return 0;

}