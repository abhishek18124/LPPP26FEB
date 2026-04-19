#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = { -10, -20, 1, 2, 3};
	int n = sizeof(arr) / sizeof(int);

	int firstMaxSoFar = INT_MIN;
	int secondMaxSoFar = INT_MIN;
	int thirdMaxSoFar = INT_MIN;

	int firstMinSoFar = INT_MAX;
	int secondMinSoFar = INT_MAX;

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

		if (arr[i] < firstMinSoFar) {
			secondMinSoFar = firstMinSoFar;
			firstMinSoFar = arr[i];
		} else if (arr[i] < secondMinSoFar) {
			secondMinSoFar = arr[i];
		}

	}

	int r1 = firstMaxSoFar * secondMaxSoFar * thirdMaxSoFar;
	int r2 = firstMaxSoFar * firstMinSoFar * secondMinSoFar;

	// if(r1 > r2) {
	// 	cout << r1 << endl;
	// } else {
	// 	cout << r2 << endl;
	// }

	cout << max(r1, r2) << endl;

	cout << max(2, max(3, max(4, 5))) << endl;
	cout << max({2, 3, 4, 5}) << endl;

	cout << min(2, min(1, min(3, 0))) << endl;
	cout << min({2, 1, 3, 0}) << endl;

	return 0;

}