class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // time : n + n + n ~ O(n)
        // space: n due to r[] = n ~ O(n)

        vector<int> r(n);
        r[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r[i] = max(r[i + 1], height[i]);
        }

        int totalSum = 0;
        int maxSoFar = 0; // since heights are >= 0
        for (int i = 0; i < n; i++) {
            // find the water trapped on top of the ith building
            maxSoFar = max(maxSoFar, height[i]);
            int wi = min(maxSoFar, r[i]) - height[i];
            totalSum += wi;
        }

        return totalSum;

    }
};