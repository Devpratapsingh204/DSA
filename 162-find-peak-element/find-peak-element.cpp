class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // Boundary checks: nums[-1] and nums[n] are treated as -Infinity
            bool leftSmaller = (i == 0) || (nums[i] > nums[i - 1]);
            bool rightSmaller = (i == n - 1) || (nums[i] > nums[i + 1]);
            
            if (leftSmaller && rightSmaller) {
                return i; // First peak element ka index return karo
            }
        }
        return 0;
    }
};