class Solution {
public:
    int twoEggDrop(int n) {
        int num =1;
        while((num*(num+1))/2 < n){
            num++;
        }
        return num;
    }
};