
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;

        for(int i = 0; i < s.size(); i++) {
            int count = 0;

            for(int j = i; j < s.size(); j++) {
                bool repeat = false;

                for(int k = i; k < j; k++) {
                    if(s[k] == s[j]) {
                        repeat = true;
                        break;
                    }
                }

                if(repeat) {
                    break;
                }

                count++;
                maxi = max(count, maxi);
            }
        }

        return maxi;
    }
};
