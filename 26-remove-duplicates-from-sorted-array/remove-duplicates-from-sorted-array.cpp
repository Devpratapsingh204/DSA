// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i=0;
//         for(int j=1; j<nums.size(); j++){
//             if(nums[i]!= nums[j]){
//                 nums[i+1] = nums[j];
//                 i++;
//             }
//         }
//         return i+1;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // we can use map
        // we should use set
        set<int>st(nums.begin(),nums.end());
        int j=0;
        for(auto i:st){
            nums[j++]=i;
        }
        return st.size();
        
    }
};