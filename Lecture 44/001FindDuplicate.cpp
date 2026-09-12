// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
	// time : O(n)
	// space: O(n)
	int findDuplicate(vector<int>& nums) {
		int n = (int)nums.size();
		vector<int> freq(n + 1, 0); // 0th index is not used since nums[] contains values in the range [1, n]

		int ans;

		for (int x : nums) {
			freq[x]++;
			if (freq[x] > 1) {
				ans = x;
				break;
			}
		}

		return ans;
	}
};