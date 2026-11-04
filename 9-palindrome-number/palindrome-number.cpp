class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x!=0 && x%10==0) return false;
        int stack[20], top=-1;
        int original=x;
        while(original>0){
            stack[++top]=original%10;
            original/=10;
        }
       
        while(x>0){
            if (stack[top--] != x % 10)
                return false;
            x /= 10;
        }
        return true;



    //     if (x < 0 || (x != 0 && x % 10 == 0))
    //         return false;

    //     int reversedHalf = 0;

    //     while (x > reversedHalf) {
    //         reversedHalf = reversedHalf * 10 + (x % 10);
    //         x /= 10;
    //     }

    // // Even length OR odd length (middle digit ignored)
    //         return (x == reversedHalf || x == reversedHalf / 10);
    }
};