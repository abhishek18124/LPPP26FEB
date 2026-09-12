#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

int main() {

	vector<int> v = {1, 2, 3};

	// time : O(nlogn) when using map<>
	// space: O(n) due to freqMap

	// time : on avg. O(n) or worst case O(n^2) when working with unordered_map<>
	// space: O(n) due freqMap

	unordered_map<int, int> freqMap;
	bool flag = false; // assume no duplicates

	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1) {
			flag = true;
			break;
		}
	}

	if (flag) {
		cout << "true";
	} else {
		cout << "false";
	}

	return 0;
}