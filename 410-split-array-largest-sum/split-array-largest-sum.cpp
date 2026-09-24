#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if we can split the array into at most 'k' 
    // subarrays such that no subarray sum exceeds 'barrier'.
    bool isPossible(vector<int>& nums, int k, long long barrier) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Agar koi single element hi barrier se bada hai, toh valid nahi hai
            if (nums[i] > barrier) return false;

            if (currentSum + nums[i] <= barrier) {
                currentSum += nums[i];
            } else {
                subarrays += 1;
                currentSum = nums[i];
            }
        }

        if (subarrays > k) return false;
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // Edge Case: Agar subarrays ki sankhya total elements se zyada hai
        if (k > n) return -1;

        // Search Space Setup:
        // low  = max element in nums (minimum possible max subarray sum)
        // high = sum of all elements in nums (maximum possible max subarray sum)
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = high;

        // Binary Search on Answer Space [low, high]
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;      // Valid max sum found, try for a smaller one on the left
                high = mid - 1;
            } else {
                low = mid + 1;  // Limit is too strict, increase sum limit on the right
            }
        }

        return ans;
    }
};