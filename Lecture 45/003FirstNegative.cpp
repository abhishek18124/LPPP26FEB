#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int arr[] = { -2, 0, -1, 2, -3, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0;     // to store the start of the window
	int j = 0;     // to store the end of the window
	queue<int>  q; // to store negative numbers in a window
	vector<int> ans; // to store first negative number for each k-sized window

	// find the first negative number in the 1st window

	while (j < k) {
		if (arr[j] < 0) {
			q.push(arr[j]);
		}
		j++;
	}

	if (q.empty()) { // 1st window has no negatives
		ans.push_back(0);
	} else { // 1st negative of the 1st window is at the front of the queue
		ans.push_back(q.front());
	}

	// find the first negative number in the remaining windows

	while (j < n) {

		// slide the window
		if (arr[i] < 0) {
			q.pop();
		}
		i++;
		if (arr[j] < 0) {
			q.push(arr[j]);
		}
		j++;

		// update the answer for the current window
		if (q.empty()) { // current window has no negatives
			ans.push_back(0);
		} else { // 1st negative of the current window is present at the front of the queue
			ans.push_back(q.front());
		}

	}


	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	// time : O(n)
	// space: O(k) due to queue, this happens when a window has all negatives

	return 0;
}

