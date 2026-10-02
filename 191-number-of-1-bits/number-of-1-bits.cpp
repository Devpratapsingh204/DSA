class Solution {
public:
    int hammingWeight(int n) {
        int setbits=0;
        while(n>0){
            setbits+=(n&1);
            n=n>>1;

        }
        return setbits;
    }
};