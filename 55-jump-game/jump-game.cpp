class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0; // The farthest index we can currently reach

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            // If current index is beyond the farthest reachable point
            if (i > maxIndex) {
                return false; // We cannot move further
            }

            // Update the farthest index we can reach
            maxIndex = max(maxIndex, i + nums[i]);
        }

        // If we finish the loop, we can reach the last index
        return true;
    }
};