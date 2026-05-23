
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:

	// time : O(n^2)
	int trap(vector<int>& height) {
		int n = height.size();
		int totalSum = 0;
		for (int i = 0; i < n; i++) {
			// find the water trapped on top of the ith building

			// li = max(h[0...i])
			int li = height[i];
			for (int j = i - 1; j >= 0; j--) {
				li = max(li, height[j]);
			}

			// ri = max(h[i...n-1])
			int ri = height[i];
			for (int j = i + 1; j < n; j++) {
				ri = max(ri, height[j]);
			}

			int wi = min(li, ri) - height[i];
			totalSum += wi;
		}
		return totalSum;
	}
};