class Solution {
public:

    // Optimal Solution: O(log N) Time Complexity using Binary Search
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        // Base Case 1: Agar k-th missing number pehle element se bhi chhota hai
        if (arr[0] - 1 >= k) return k;

        // Base Case 2: Agar k-th missing number saare elements ke baad lie karta hai
        if (arr[n-1] - n < k) return arr[n-1] + (k - (arr[n-1] - n));

        int low = 0, high = n - 1;
        int res = 0; // Store karega wo last index jahan tak missing numbers < k hain

        // Binary Search Space: Search space [0, n-1]
        while (low <= high) {
            int mid = low + (high - low) / 2; // Mid index calculate (Syntax fixed)

            // arr[mid] - mid - 1 gives total missing numbers up to index 'mid'
            if (arr[mid] - mid - 1 < k) {
                res = mid;      // Mid index answer ke liye valid hai, store karo
                low = mid + 1;  // Right side check karo aur k-th missing ke paas jao
            } 
            else {
                high = mid - 1; // Left side shift karo kyunki missing numbers >= k ho gaye
            }
        }

        // Final Result Calculation:
        // arr[res] = last element before k-th missing number
        // (k - (arr[res] - res - 1)) = jitne missing numbers aur aage add karne hain
        return arr[res] + (k - (arr[res] - res - 1));
    }

    // Brute Force Approach: O(N) Time Complexity
    int findKthPositives(vector<int>& arr, int k) {
        // Har element ke liye: agar element current k se chhota ya equal hai, 
        // toh missing number dynamic offset shift ho jata hai (k++)
        for (auto i : arr) {
            if (i <= k) {
                k++;
            } else {
                break; // Jab element k se bada ho jaye, shifting ruk jati hai
            }
        }

        return k;
    }
};