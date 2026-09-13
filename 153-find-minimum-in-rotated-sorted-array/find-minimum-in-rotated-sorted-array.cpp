class Solution {
public:
    int findMin(vector<int>& nums) {
        int sma=nums[0];
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<sma){
                sma=nums[i];
            }
        }
        return sma;
    }
};