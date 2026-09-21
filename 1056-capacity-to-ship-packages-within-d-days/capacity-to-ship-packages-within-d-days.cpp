class Solution {
private:
    // Helper function: Calculates how many days are needed for a given capacity
    int findDays(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                days += 1;         // Move to next day
                load = weights[i]; // Load current package on the new day
            } else {
                load += weights[i]; // Add package to current day's load
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = weights[0];
        int high = 0;

        // Search space setup:
        // low  = max element in weights (minimum possible capacity)
        // high = sum of all weights (maximum possible capacity)
        for (int i = 0; i < weights.size(); i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }

        int ans = high;

        // Binary search on capacity range [low, high]
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int daysRequired = findDays(weights, mid);

            if (daysRequired <= days) {
                ans = mid;      // Found a valid capacity, try to find a smaller one
                high = mid - 1; 
            } else {
                low = mid + 1;  // Capacity is too small, need more capacity
            }
        }

        return ans;
    }
};