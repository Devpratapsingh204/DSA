class Solution {
public:
    // Function to calculate total hours at given speed
    long long calculateTotalHours(vector<int>& piles, int speed) {
        long long totalH = 0;

        for (int bananas : piles) {
            totalH += ceil((double)bananas / (double)speed);
        }

        return totalH;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        // Find maximum element
        int maxPile = *max_element(piles.begin(), piles.end());

        // Initialize low and high pointers
        int low = 1, high = maxPile;
        int ans = maxPile;

        // Binary search on answer space
        while (low <= high) {
            int mid = (low + high) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            // If possible, try smaller speed
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, try larger speed
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};