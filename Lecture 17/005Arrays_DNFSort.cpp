/*

https://leetcode.com/problems/sort-colors/description/

*/

class Solution {
public:
	void sortColors(vector<int>& arr) {
		int n = arr.size();

		int low = 0;
		int mid = 0;
		int high = n - 1;

		// arr[0...low-1] -> zeros
		// arr[low...mid-1] -> ones
		// arr[mid...high] -> unknown
		// arr[high+1...n-1] -> twos

		// time : O(n)

		while (mid <= high) {

			if (arr[mid] == 0) {
				// put arr[mid] to zeros
				swap(arr[mid], arr[low]);
				low++;
				mid++;
			} else if (arr[mid] == 1) {
				// put arr[mid] to ones
				mid++;
			} else {
				// arr[mid] == 2
				// put arr[mid] to twos
				swap(arr[mid], arr[high]);
				high--;
			}

		}

	}
};