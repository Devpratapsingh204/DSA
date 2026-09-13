class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool ins=false;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==target){
                ins=true;
                break;
            }
        }
        return ins;
    }
};