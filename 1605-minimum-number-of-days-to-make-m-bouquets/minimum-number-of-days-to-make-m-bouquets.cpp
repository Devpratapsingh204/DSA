class Solution {
private:
    // Check karta hai ki 'day' tak 'm' bouquets ban sakte hain ya nahi
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int noOfBouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++; // Continuous flower bloom ho gaya
            } else {
                noOfBouquets += (count / k); // Jinte complete bouquets bane unhe add karo
                count = 0; // Sequence break
            }
        }
        noOfBouquets += (count / k); // Last continuous segment ke bouquets count karo

        return noOfBouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k; // Total required flowers
        int n = bloomDay.size();

        // Edge case: Total flowers required > total flowers available
        if (val > n) return -1;

        int low = bloomDay[0];
        int high = bloomDay[0];

        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        // Binary Search on Answer Space [low, high]
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1; // Left half mein aur chhota day search karo
            } else {
                low = mid + 1;  // Right half mein jao (flowers aur chahiye)
            }
        }

        // Loop end hone par 'low' minimum valid day ko point karega
        return low; 
    }
};