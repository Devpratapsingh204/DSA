class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int mx=nums[0];
        int mn=nums[0];
        for(int x=0; x<nums.size(); x++){
            mx=max(nums[x], mx);
            mn=min(nums[x], mn);
        }
        return gcd(mx, mn);
    }
};