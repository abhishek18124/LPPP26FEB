/*

e.g.

input
10 2 5
4 3 2 2 4 3 5 4 5 2

output
2 2 2 3 3 4 4 4 5 5

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	int l, r;
	cin >> l >> r;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> freqMap(r - l + 1, 0);
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		freqMap[x - l]++;
	}

	for (int i = 0; i < r - l + 1; i++) {
		// print 'i+l' freqMap[i] times
		for (int j = 1; j <= freqMap[i]; j++) {
			cout << i + l << " ";
		}
	}

	return 0;
}