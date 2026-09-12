class Solution {
public:
    // time : O(n)
    // space: O(1) but we are modifying the array
    int findDuplicate(vector<int>& nums) {

        while (true) {
            int x = nums[0];
            if (nums[x] == x) {
                return x;
            }
            swap(nums[0], nums[x]);
        }

    }
};