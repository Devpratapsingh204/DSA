class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest=nums[0];
        int largest=nums[0];
        for(int i=1; i<nums.size();i++){
            smallest=min(smallest, nums[i]);
            largest=max(largest,nums[i]);
        }
        int gcd=1;
        for(int i=1; i<=smallest; i++){
            if(smallest%i==0 && largest%i==0){
                gcd=i;
            }
        }
        return gcd;
    }
};