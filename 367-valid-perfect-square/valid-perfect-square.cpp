class Solution {
public:
    bool isPerfectSquare(int num) {
        long long st = 1, ed = num;

        while (st <= ed) {
            long long mid = st + (ed - st) / 2;

            if (mid * mid == num)
                return true;
            else if (mid * mid < num)
                st = mid + 1;
            else
                ed = mid - 1;
        }

        return false;
    }
};