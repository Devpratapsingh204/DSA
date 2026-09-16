class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Agar pehle se hi last index par hain

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        // Last index par jump maarne ki zaroorat nahi hai, isliye i < n - 1
        for (int i = 0; i < n - 1; ++i) {
            // Check karo ki is index se sabse door kahan tak ja sakte hain
            farthest = max(farthest, i + nums[i]);

            // Jab hum current jump ki boundary par pahunch jaayein
            if (i == currentEnd) {
                jumps++;             // Ek jump count badhao
                currentEnd = farthest; // Agli jump ki boundary update karo
            }
        }

        return jumps;
    }
};