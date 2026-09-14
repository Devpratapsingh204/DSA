class Solution {
public:
    // Change return type to long long to prevent integer overflow
    long long calculateTotalHours(vector<int>& piles, int speed) {
        long long totalH = 0;
        for (int bananas : piles) {
            // Integer division trick equivalent to ceil(bananas / speed)
            totalH += (bananas + (long long)speed - 1) / speed;
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxPile;
        int ans = maxPile;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Store result in long long
            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};