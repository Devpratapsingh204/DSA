class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0;
        int fast = 0;

        // finding cycle first...

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        // find entrance of cycle..
        slow = 0;
        
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};