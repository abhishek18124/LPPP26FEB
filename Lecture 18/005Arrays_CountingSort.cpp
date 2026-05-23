/*

e.g.

input
9 3
1 0 3 2 3 1 2 0 2

output
0 0 1 1 2 2 2 3 3

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 1. build a freqMap

	vector<int> freqMap(k + 1, 0);
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		freqMap[x]++;
		// freqMap[arr[i]]++;
	}

	// for (int i = 0; i <= k; i++) {
	// 	cout << "freq[" << i << "] = " << freqMap[i] << endl;
	// }

	// 2. use the freqMap to print sorted array

	for (int i = 0; i <= k; i++) {
		// print 'i' freqMap[i] times
		for (int j = 1; j <= freqMap[i]; j++) {
			cout << i << " ";
		}
	}

	// time : n.const + n.const ~ O(n)
	// space: k+1 due to freqMap ~ O(k)


	return 0;
}