class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = nums[0];
        
        // Find maximum element for high limit
        for (int i = 0; i < nums.size(); i++) {
            high = max(high, nums[i]);
        }

        int ans = high;

        // Binary search for the smallest valid divisor
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Simple sum calculation for mid divisor
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                // Ceiling division formula: ceil(nums[i] / mid)
                sum += (nums[i] + mid - 1) / mid; 
            }

            // Check if sum is within threshold
            if (sum <= threshold) {
                ans = mid;      // Potential answer found
                high = mid - 1; // Search left for a smaller divisor
            } else {
                low = mid + 1;  // Sum is too large, need a larger divisor
            }
        }

        return ans;
    }
};