class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n - 1;

        int l = 0; // max(height[0...i])
        int r = 0; // max(height[j...n-1])

        int totalSum = 0;

        while (i <= j) {
            l = max(l, height[i]);
            r = max(r, height[j]);
            if (l < r) {
                int wi = l - height[i];
                totalSum += wi;
                i++;
            } else {
                int wj = r - height[j];
                totalSum += wj;
                j--;
            }

        }

        return totalSum;
    }
};