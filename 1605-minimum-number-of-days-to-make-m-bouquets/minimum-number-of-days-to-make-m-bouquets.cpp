class Solution {
private:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int noOfBouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                noOfBouquets += (count / k);
                count = 0;
            }
        }
        noOfBouquets += (count / k);

        return noOfBouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // Safe Check: Agar total flowers required (m * k) > total available (n)
        // Iso 'm > n / k' likhne se integer overflow nahi hota
        if (m > n / k) return -1;

        int low = bloomDay[0];
        int high = bloomDay[0];

        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        // Standard Binary Search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1; // Aur chhota day try karo
            } else {
                low = mid + 1;  // Bigger day try karo
            }
        }

        return low;
    }
};