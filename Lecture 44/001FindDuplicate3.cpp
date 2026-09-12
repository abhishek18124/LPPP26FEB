class Solution {
public:
    // time : O(n) // space : O(1) without modifying the array
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        // slow and fast are at the meeting point
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // slow and fast are the start of the cycle
        return slow; // return fast;
    }
};