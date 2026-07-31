class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> preSumMap;
        
        // Base case: prefix sum of 0 has appeared once (before index 0)
        preSumMap[0] = 1;
        
        long long sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            long long rem = sum - k;
            
            // Add all occurrences of (sum - k) to the count
            if (preSumMap.find(rem) != preSumMap.end()) {
                count += preSumMap[rem];
            }
            
            // Store/increment frequency of current prefix sum
            preSumMap[sum]++;
        }

        return count;
    }
};