class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // time : n + n + n ~ O(n)
        // space: n due to l[] + n due to r[] = 2n ~ O(n)

        vector<int> l(n);
        l[0] = height[0];
        for (int i = 1; i < n; i++) {
            l[i] = max(l[i - 1], height[i]);
        }

        vector<int> r(n);
        r[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r[i] = max(r[i + 1], height[i]);
        }

        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            // find the water trapped on top of the ith building
            int wi = min(l[i], r[i]) - height[i];
            totalSum += wi;
        }

        return totalSum;

    }
};