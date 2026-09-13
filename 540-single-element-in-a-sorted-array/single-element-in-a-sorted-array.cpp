class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Check: mid ko humeshaa Even index par lana hai
            if (mid % 2 == 1) {
                mid--;
            }
            
            // Core Logic: Even-Odd Pair Check
            if (nums[mid] == nums[mid + 1]) {
                // Duplicate pair sahi position par hai (Left side sorted/normal hai)
                low = mid + 2; // Unique element Right half me hai
            } else {
                // Pair broken hai, unique element Left half ya 'mid' par hai
                high = mid;
            }
        }
        
        return nums[low];
    }
};