#include<iostream>
#include<climits>

using namespace std;

int main() {

	// time : O(n)
	// space: O(1)

	int n;
	cin >> n;

	int maxSoFar = INT_MIN; // to track the "maximum or largest" element seen so far

	int i = 1;

	while (i <= n) {
		int x;
		cin >> x;
		if (x > maxSoFar) {
			maxSoFar = x;
		}
		i = i + 1;
	}

	cout << maxSoFar << endl;

	return 0;
}